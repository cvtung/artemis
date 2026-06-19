#include "gamepadmappermanager.h"
#include "mappingmanager.h"

#include <SDL_joystick.h>
#include <SDL_gamecontroller.h>

#include <QDebug>
#include <QSettings>

// ---------------------------------------------------------------------------
// 18 standard logical inputs (confirmed with user)
// ---------------------------------------------------------------------------
// Indices 0-17 map to these fields in SDL mapping string order.
static const GamepadMapperManager::BindingEntry k_LogicalInputs[] = {
    { "a",             QT_TR_NOOP("A")              },
    { "b",             QT_TR_NOOP("B")              },
    { "x",             QT_TR_NOOP("X")              },
    { "y",             QT_TR_NOOP("Y")              },
    { "back",          QT_TR_NOOP("Back")           },
    { "guide",         QT_TR_NOOP("Guide")          },
    { "start",         QT_TR_NOOP("Start")          },
    { "leftstick",     QT_TR_NOOP("LS")             },
    { "rightstick",    QT_TR_NOOP("RS")             },
    { "leftshoulder",  QT_TR_NOOP("LB")             },
    { "rightshoulder", QT_TR_NOOP("RB")             },
    { "dpup",          QT_TR_NOOP("DPad Up")        },
    { "dpdown",        QT_TR_NOOP("DPad Down")      },
    { "dpleft",        QT_TR_NOOP("DPad Left")      },
    { "dpright",       QT_TR_NOOP("DPad Right")     },
    { "lefttrigger",   QT_TR_NOOP("LT")             },
    { "righttrigger",  QT_TR_NOOP("RT")             },
    { "misc",          QT_TR_NOOP("Misc")           },
};

// ---------------------------------------------------------------------------
// Helpers
// ---------------------------------------------------------------------------

static QString guidToString(SDL_JoystickGUID guid)
{
    char buf[65];
    SDL_JoystickGetGUIDString(guid, buf, sizeof(buf));
    return QString::fromLatin1(buf);
}

static int sdlButtonForField(const QString& field)
{
    if (field == "a")             return SDL_CONTROLLER_BUTTON_A;
    if (field == "b")             return SDL_CONTROLLER_BUTTON_B;
    if (field == "x")             return SDL_CONTROLLER_BUTTON_X;
    if (field == "y")             return SDL_CONTROLLER_BUTTON_Y;
    if (field == "back")          return SDL_CONTROLLER_BUTTON_BACK;
    if (field == "guide")         return SDL_CONTROLLER_BUTTON_GUIDE;
    if (field == "start")         return SDL_CONTROLLER_BUTTON_START;
    if (field == "leftstick")     return SDL_CONTROLLER_BUTTON_LEFTSTICK;
    if (field == "rightstick")    return SDL_CONTROLLER_BUTTON_RIGHTSTICK;
    if (field == "leftshoulder")  return SDL_CONTROLLER_BUTTON_LEFTSHOULDER;
    if (field == "rightshoulder") return SDL_CONTROLLER_BUTTON_RIGHTSHOULDER;
    if (field == "dpup")          return SDL_CONTROLLER_BUTTON_DPAD_UP;
    if (field == "dpdown")        return SDL_CONTROLLER_BUTTON_DPAD_DOWN;
    if (field == "dpleft")        return SDL_CONTROLLER_BUTTON_DPAD_LEFT;
    if (field == "dpright")       return SDL_CONTROLLER_BUTTON_DPAD_RIGHT;
    if (field == "misc")          return SDL_CONTROLLER_BUTTON_MISC1;
    return -1;
}

static int sdlAxisForField(const QString& field)
{
    if (field == "lefttrigger")  return SDL_CONTROLLER_AXIS_TRIGGERLEFT;
    if (field == "righttrigger") return SDL_CONTROLLER_AXIS_TRIGGERRIGHT;
    return -1;
}

// ---------------------------------------------------------------------------
// Construction
// ---------------------------------------------------------------------------

GamepadMapperManager::GamepadMapperManager(QObject* parent)
    : QObject(parent)
    , m_RescanTimer(new QTimer(this))
    , m_CaptureTimer(new QTimer(this))
    , m_SelectedDeviceIndex(-1)
    , m_Controller(nullptr)
    , m_Joystick(nullptr)
    , m_CapturingInputId(-1)
    , m_CaptureDebounceFrames(0)
    , m_CaptureFrameCount(0)
    , m_PendingDeviceName()
{
    m_RescanTimer->setInterval(1000);
    m_RescanTimer->setSingleShot(false);
    connect(m_RescanTimer, &QTimer::timeout, this, &GamepadMapperManager::rescan);

    m_CaptureTimer->setInterval(33); // ~30 fps
    m_CaptureTimer->setSingleShot(false);
    connect(m_CaptureTimer, &QTimer::timeout, this, &GamepadMapperManager::onCaptureTimerFired);
}

// ---------------------------------------------------------------------------
// attachedDevices property
// ---------------------------------------------------------------------------

QVariantList GamepadMapperManager::attachedDevices() const
{
    QVariantList list;
    for (const DeviceInfo& dev : m_Devices) {
        QVariantMap map;
        map["name"] = dev.name;
        map["guid"] = dev.guid;

        // mapped = SDL knows a community mapping for this device index
        bool communityMapped = SDL_IsGameController(dev.index);

        // userSaved = user has a custom mapping stored in QSettings
        QSettings settings;
        bool userSaved = false;
        int count = settings.beginReadArray("gcmapping");
        for (int i = 0; i < count; i++) {
            settings.setArrayIndex(i);
            if (settings.value("guid").toString() == dev.guid) {
                userSaved = true;
                break;
            }
        }
        settings.endArray();

        map["mapped"] = communityMapped;
        map["userSaved"] = userSaved;
        list.append(map);
    }
    return list;
}

// ---------------------------------------------------------------------------
// Page lifecycle
// ---------------------------------------------------------------------------

void GamepadMapperManager::open()
{
    SDL_LogInfo(SDL_LOG_CATEGORY_APPLICATION,
                "GamepadMapper: open()");

    // Snapshot current bindings so resetToDefault() works
    m_DefaultBindings = m_Bindings;

    // Start rescan timer for hot-plug detection
    m_RescanTimer->start();
}

void GamepadMapperManager::close()
{
    SDL_LogInfo(SDL_LOG_CATEGORY_APPLICATION,
                "GamepadMapper: close()");
    m_RescanTimer->stop();
    m_CaptureTimer->stop();
    m_CapturingInputId = -1;
    closeDevice();
    m_Devices.clear();
    m_Bindings.clear();
    m_DefaultBindings.clear();
    m_SelectedDeviceIndex = -1;
}

// ---------------------------------------------------------------------------
// Device enumeration
// ---------------------------------------------------------------------------

void GamepadMapperManager::rescan()
{
    m_Devices.clear();

    int numSticks = SDL_NumJoysticks();
    SDL_LogDebug(SDL_LOG_CATEGORY_APPLICATION,
                 "GamepadMapper: rescan() — SDL_NumJoysticks() = %d",
                 numSticks);
    for (int i = 0; i < numSticks; i++) {
        DeviceInfo dev;
        dev.index = i;

        const char* name = SDL_JoystickNameForIndex(i);
        dev.name = name ? QString::fromUtf8(name) : QStringLiteral("Unknown");
        dev.guid = guidToString(SDL_JoystickGetDeviceGUID(i));
        m_Devices.append(dev);

        SDL_LogDebug(SDL_LOG_CATEGORY_APPLICATION,
                     "GamepadMapper:   joystick[%d] = \"%s\" (guid=%s)",
                     i, qPrintable(dev.name), qPrintable(dev.guid));
    }

    // If the currently selected device was removed, invalidate
    if (m_SelectedDeviceIndex >= m_Devices.size()) {
        m_SelectedDeviceIndex = -1;
        closeDevice();
        m_Bindings.clear();
    }

    emit attachedDevicesChanged();

    // Auto-select a device that was requested before the scan
    if (!m_PendingDeviceName.isEmpty()) {
        for (int i = 0; i < m_Devices.size(); i++) {
            if (m_Devices[i].name == m_PendingDeviceName) {
                selectDeviceByIndex(i);
                break;
            }
        }
        m_PendingDeviceName.clear();
    }
}

// ---------------------------------------------------------------------------
// Device selection
// ---------------------------------------------------------------------------

void GamepadMapperManager::selectDeviceByIndex(int index)
{
    if (index < 0 || index >= m_Devices.size()) {
        emit errorOccurred(tr("Invalid device index"));
        return;
    }

    SDL_LogInfo(SDL_LOG_CATEGORY_APPLICATION,
                "GamepadMapper: selectDeviceByIndex(%d) — \"%s\"",
                index, qPrintable(m_Devices[index].name));
    closeDevice();
    m_Bindings.clear();
    m_SelectedDeviceIndex = index;
    openDevice();
}

void GamepadMapperManager::selectDeviceByName(QString name)
{
    m_PendingDeviceName = name;

    for (int i = 0; i < m_Devices.size(); i++) {
        if (m_Devices[i].name == name) {
            selectDeviceByIndex(i);
            return;
        }
    }
}

// ---------------------------------------------------------------------------
// Open / close the physical device
// ---------------------------------------------------------------------------

void GamepadMapperManager::openDevice()
{
    if (m_SelectedDeviceIndex < 0 || m_SelectedDeviceIndex >= m_Devices.size())
        return;

    const DeviceInfo& dev = m_Devices[m_SelectedDeviceIndex];
    SDL_LogInfo(SDL_LOG_CATEGORY_APPLICATION,
                "GamepadMapper: Opening device index %d (\"%s\", guid=%s)",
                dev.index, qPrintable(dev.name), qPrintable(dev.guid));

    // Try opening as a game controller first (community or user mapping exists)
    m_Controller = SDL_GameControllerOpen(dev.index);
    if (m_Controller) {
        m_Joystick = SDL_GameControllerGetJoystick(m_Controller);
    } else {
        // No existing mapping; open raw joystick for capture
        m_Joystick = SDL_JoystickOpen(dev.index);
    }

    if (!m_Joystick) {
        emit errorOccurred(tr("Failed to open device: %1").arg(SDL_GetError()));
        return;
    }

    // Populate bindings from the existing mapping (if any)
    if (m_Controller) {
        char* mappingStr = SDL_GameControllerMapping(m_Controller);
        if (mappingStr) {
            QString mappingQStr = QString::fromUtf8(mappingStr);
            SDL_free(mappingStr);

            // Parse field:value pairs from the mapping string
            // Format: "GUID,Name,field1:value1,field2:value2,..."
            int commaPos = mappingQStr.indexOf(',');
            if (commaPos >= 0) {
                commaPos = mappingQStr.indexOf(',', commaPos + 1);
            }
            if (commaPos >= 0) {
                QString pairsStr = mappingQStr.mid(commaPos + 1);
                QStringList pairs = pairsStr.split(',', Qt::SkipEmptyParts);
                for (const QString& pair : pairs) {
                    int colonPos = pair.indexOf(':');
                    if (colonPos >= 0) {
                        QString field = pair.left(colonPos);
                        QString value = pair.mid(colonPos + 1);
                        // Store by looking up logical input id
                        for (int i = 0; i < k_LogicalInputCount; i++) {
                            if (k_LogicalInputs[i].sdlField == field) {
                                m_Bindings[i] = value;
                                break;
                            }
                        }
                    }
                }
            }
        }
    }
    // For unmapped devices, all bindings stay empty — the user defines them.
}

void GamepadMapperManager::closeDevice()
{
    if (m_Controller) {
        SDL_LogInfo(SDL_LOG_CATEGORY_APPLICATION,
                    "GamepadMapper: Closing game controller");
        SDL_GameControllerClose(m_Controller);
        m_Controller = nullptr;
        m_Joystick = nullptr;
    } else if (m_Joystick) {
        SDL_LogInfo(SDL_LOG_CATEGORY_APPLICATION,
                    "GamepadMapper: Closing raw joystick");
        SDL_JoystickClose(m_Joystick);
        m_Joystick = nullptr;
    }
}

// ---------------------------------------------------------------------------
// Capture
// ---------------------------------------------------------------------------

void GamepadMapperManager::startCapture(int logicalInputId)
{
    if (!m_Joystick || logicalInputId < 0 || logicalInputId >= k_LogicalInputCount) {
        return;
    }

    SDL_LogInfo(SDL_LOG_CATEGORY_APPLICATION,
                "GamepadMapper: Starting capture for logicalInputId=%d (%s)",
                logicalInputId, k_LogicalInputs[logicalInputId].sdlField);

    // Snapshot initial state
    m_InitialAxes.clear();
    m_InitialButtons.clear();
    m_InitialHats.clear();

    int numAxes = SDL_JoystickNumAxes(m_Joystick);
    int numButtons = SDL_JoystickNumButtons(m_Joystick);
    int numHats = SDL_JoystickNumHats(m_Joystick);

    for (int a = 0; a < numAxes; a++)
        m_InitialAxes[a] = SDL_JoystickGetAxis(m_Joystick, a);

    for (int b = 0; b < numButtons; b++)
        m_InitialButtons[b] = SDL_JoystickGetButton(m_Joystick, b);

    for (int h = 0; h < numHats; h++)
        m_InitialHats[h] = SDL_JoystickGetHat(m_Joystick, h);

    m_CapturingInputId = logicalInputId;
    m_CaptureDebounceFrames = 0;
    m_CaptureFrameCount = 0;
    m_CaptureTimer->start();
}

void GamepadMapperManager::cancelCapture()
{
    m_CaptureTimer->stop();
    m_CapturingInputId = -1;
}

void GamepadMapperManager::onCaptureTimerFired()
{
    if (!m_Joystick || m_CapturingInputId < 0) {
        m_CaptureTimer->stop();
        m_CapturingInputId = -1;
        return;
    }

    // Debounce: skip first N frames to let OS settle
    if (m_CaptureDebounceFrames < k_CaptureDebounceFrames) {
        m_CaptureDebounceFrames++;
        // Update initial snapshots each debounce frame to avoid picking up
        // stale transient values as "captured" input
        int numAxes = SDL_JoystickNumAxes(m_Joystick);
        int numButtons = SDL_JoystickNumButtons(m_Joystick);
        int numHats = SDL_JoystickNumHats(m_Joystick);
        for (int a = 0; a < numAxes; a++)
            m_InitialAxes[a] = SDL_JoystickGetAxis(m_Joystick, a);
        for (int b = 0; b < numButtons; b++)
            m_InitialButtons[b] = SDL_JoystickGetButton(m_Joystick, b);
        for (int h = 0; h < numHats; h++)
            m_InitialHats[h] = SDL_JoystickGetHat(m_Joystick, h);
        return;
    }

    int numAxes = SDL_JoystickNumAxes(m_Joystick);
    int numButtons = SDL_JoystickNumButtons(m_Joystick);
    int numHats = SDL_JoystickNumHats(m_Joystick);

    // Check buttons: first button that went from 0 to 1
    for (int b = 0; b < numButtons; b++) {
        Uint8 current = SDL_JoystickGetButton(m_Joystick, b);
        Uint8 initial = m_InitialButtons.value(b, 0);
        if (current == 1 && initial == 0) {
            QString binding = QString("b%1").arg(b);
            m_Bindings[m_CapturingInputId] = binding;
            int capturedId = m_CapturingInputId;
            m_CaptureTimer->stop();
            m_CapturingInputId = -1;
            emit bindingCaptured(capturedId, binding);
            return;
        }
        else if (current == 0 && initial == 1) {
            // Button was released — update baseline so a subsequent press
            // is caught even if the user was holding the button during debounce.
            m_InitialButtons[b] = 0;
        }
    }

    // Check axes: first axis with delta > 16000
    for (int a = 0; a < numAxes; a++) {
        Sint16 current = SDL_JoystickGetAxis(m_Joystick, a);
        Sint16 initial = m_InitialAxes.value(a, 0);
        Sint16 delta = current - initial;
        if (qAbs(delta) > 16000) {
            QString binding = QString("a%1%2").arg(a).arg(delta > 0 ? "+" : "-");
            m_Bindings[m_CapturingInputId] = binding;
            int capturedId = m_CapturingInputId;
            m_CaptureTimer->stop();
            m_CapturingInputId = -1;
            emit bindingCaptured(capturedId, binding);
            return;
        }
        // If the axis returns close to center, update baseline so a new
        // deflection is detectable.
        if (qAbs(current) < 8000) {
            m_InitialAxes[a] = current;
        }
    }

    // Check hats: first hat that changed from 0
    for (int h = 0; h < numHats; h++) {
        Uint8 current = SDL_JoystickGetHat(m_Joystick, h);
        Uint8 initial = m_InitialHats.value(h, 0);
        if (current != initial) {
            // Only capture if it's a directional press (not the release back to 0)
            if (current != SDL_HAT_CENTERED) {
                QString binding = QString("h%1.%2").arg(h).arg(current);
                m_Bindings[m_CapturingInputId] = binding;
                int capturedId = m_CapturingInputId;
                m_CaptureTimer->stop();
                m_CapturingInputId = -1;
                emit bindingCaptured(capturedId, binding);
                return;
            }
        }
        else {
            // Hat returned to center — update baseline so a subsequent
            // directional press is detected.
            m_InitialHats[h] = current;
        }
    }

    // Timeout
    m_CaptureFrameCount++;
    if (m_CaptureFrameCount >= k_CaptureMaxFrames) {
        m_CaptureTimer->stop();
        m_CapturingInputId = -1;
        emit captureTimeout();
    }
}

// ---------------------------------------------------------------------------
// Binding manipulation
// ---------------------------------------------------------------------------

void GamepadMapperManager::clearBinding(int logicalInputId)
{
    if (logicalInputId >= 0 && logicalInputId < k_LogicalInputCount) {
        m_Bindings.remove(logicalInputId);
    }
}

void GamepadMapperManager::resetToDefault()
{
    m_Bindings = m_DefaultBindings;
}

void GamepadMapperManager::commitMapping()
{
    if (m_SelectedDeviceIndex < 0 || m_SelectedDeviceIndex >= m_Devices.size()) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION,
                     "GamepadMapper: commitMapping() failed — no device selected");
        emit errorOccurred(tr("No device selected"));
        return;
    }

    const DeviceInfo& dev = m_Devices[m_SelectedDeviceIndex];
    QString mappingStr = buildSdlMappingString();
    SDL_LogInfo(SDL_LOG_CATEGORY_APPLICATION,
                "GamepadMapper: commitMapping() for \"%s\" — mapping=\"%s\"",
                qPrintable(dev.name), qPrintable(mappingStr));

    if (mappingStr.isEmpty()) {
        emit errorOccurred(tr("No bindings to save"));
        return;
    }

    // Apply to SDL immediately
    int ret = SDL_GameControllerAddMapping(qPrintable(mappingStr));
    if (ret < 0) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION,
                     "GamepadMapper: SDL_GameControllerAddMapping failed: %s",
                     SDL_GetError());
        emit errorOccurred(tr("Failed to add mapping: %1").arg(SDL_GetError()));
        return;
    }

    SDL_LogInfo(SDL_LOG_CATEGORY_APPLICATION,
                "GamepadMapper: SDL_GameControllerAddMapping returned %d", ret);

    // Persist via MappingManager
    MappingManager manager;
    manager.addMapping(mappingStr);
    manager.save();

    // Re-apply all mappings to activate the new one
    manager.applyMappings();

    // Update our own bindings from the now-active controller
    closeDevice();
    openDevice();

    emit mappingCommitted();
}

void GamepadMapperManager::deleteMappingForDevice(QString guid)
{
    MappingManager manager;
    manager.deleteMapping(guid);
    manager.applyMappings();

    // Close and re-open to refresh
    closeDevice();
    openDevice();
}

// ---------------------------------------------------------------------------
// Logical input definition (static)
// ---------------------------------------------------------------------------

QVariantList GamepadMapperManager::logicalInputs() const
{
    QVariantList list;
    for (int i = 0; i < k_LogicalInputCount; i++) {
        QVariantMap map;
        map["id"] = i;
        map["label"] = tr(k_LogicalInputs[i].humanLabel);
        list.append(map);
    }
    return list;
}

// ---------------------------------------------------------------------------
// Human-readable binding description
// ---------------------------------------------------------------------------

QString GamepadMapperManager::currentBindingDescription(int logicalInputId) const
{
    if (logicalInputId < 0 || logicalInputId >= k_LogicalInputCount)
        return QString();

    if (!m_Bindings.contains(logicalInputId))
        return tr("(unbound)");

    QString val = m_Bindings.value(logicalInputId);

    // Decode button binding: "b0", "b1", ...
    if (val.startsWith('b')) {
        bool ok;
        int num = val.mid(1).toInt(&ok);
        if (ok)
            return tr("Button %1").arg(num);
    }

    // Decode axis binding: "a0+", "a1-", ...
    if (val.startsWith('a')) {
        // Find first non-digit after 'a'
        int i = 1;
        while (i < val.size() && val[i].isDigit())
            i++;
        bool ok;
        int num = val.mid(1, i - 1).toInt(&ok);
        if (ok && i < val.size()) {
            QString dir = (val[i] == '+') ? tr("+") : tr("-");
            return tr("Axis %1%2").arg(num).arg(dir);
        }
        if (ok)
            return tr("Axis %1").arg(num);
    }

    // Decode hat binding: "h0.1" (1=up, 2=right, 4=down, 8=left)
    if (val.startsWith('h')) {
        int dotPos = val.indexOf('.');
        if (dotPos > 0) {
            bool ok;
            int hatNum = val.mid(1, dotPos - 1).toInt(&ok);
            if (ok) {
                int mask = val.mid(dotPos + 1).toInt(&ok);
                if (ok) {
                    QString dir;
                    if (mask & SDL_HAT_UP)    dir = tr("Up");
                    if (mask & SDL_HAT_DOWN)  dir = tr("Down");
                    if (mask & SDL_HAT_LEFT)  dir = tr("Left");
                    if (mask & SDL_HAT_RIGHT) dir = tr("Right");
                    return tr("Hat %1 %2").arg(hatNum).arg(dir);
                }
            }
        }
    }

    return val;
}

// ---------------------------------------------------------------------------
// Private helpers
// ---------------------------------------------------------------------------

GamepadMapperManager::BindingEntry GamepadMapperManager::bindingEntryForLogicalInput(int logicalInputId) const
{
    if (logicalInputId >= 0 && logicalInputId < k_LogicalInputCount)
        return k_LogicalInputs[logicalInputId];

    return BindingEntry();
}

QString GamepadMapperManager::buildSdlMappingString() const
{
    if (m_SelectedDeviceIndex < 0 || m_SelectedDeviceIndex >= m_Devices.size())
        return QString();

    const DeviceInfo& dev = m_Devices[m_SelectedDeviceIndex];
    QString name = dev.name;

    // SDL uses commas to separate entries in the mapping, so we must
    // replace any commas in the device name with spaces
    name.replace(',', ' ');

    QString mapping = dev.guid + "," + name;

    for (int i = 0; i < k_LogicalInputCount; i++) {
        if (m_Bindings.contains(i)) {
            mapping += "," + k_LogicalInputs[i].sdlField + ":" + m_Bindings.value(i);
        }
    }

    return mapping;
}
