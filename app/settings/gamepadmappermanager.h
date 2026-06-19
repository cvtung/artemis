#pragma once

#include <QObject>
#include <QTimer>
#include <QVariantList>

#include "SDL_compat.h"

class GamepadMapperManager : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QVariantList attachedDevices READ attachedDevices NOTIFY attachedDevicesChanged)

public:
    explicit GamepadMapperManager(QObject* parent = nullptr);

    QVariantList attachedDevices() const;

    Q_INVOKABLE void open();
    Q_INVOKABLE void close();
    Q_INVOKABLE void rescan();
    Q_INVOKABLE void selectDeviceByIndex(int index);
    Q_INVOKABLE void selectDeviceByName(QString name);
    Q_INVOKABLE void startCapture(int logicalInputId);
    Q_INVOKABLE void cancelCapture();
    Q_INVOKABLE void clearBinding(int logicalInputId);
    Q_INVOKABLE void resetToDefault();
    Q_INVOKABLE void commitMapping();
    Q_INVOKABLE void deleteMappingForDevice(QString guid);
    Q_INVOKABLE QVariantList logicalInputs() const;
    Q_INVOKABLE QString currentBindingDescription(int logicalInputId) const;

    struct BindingEntry {
        QString sdlField;    // e.g. "a", "b", "lefttrigger", "dpup"
        const char* humanLabel;  // e.g. "A", "B" — const char* for tr() compatibility
    };

signals:
    void attachedDevicesChanged();
    void bindingCaptured(int logicalInputId, QString bindingString);
    void captureTimeout();
    void mappingCommitted();
    void errorOccurred(QString message);

private slots:
    void onCaptureTimerFired();

private:
    struct DeviceInfo {
        int index;
        QString name;
        QString guid;
    };

    void openDevice();
    void closeDevice();
    QString buildSdlMappingString() const;
    BindingEntry bindingEntryForLogicalInput(int logicalInputId) const;

    QTimer* m_RescanTimer;
    QTimer* m_CaptureTimer;

    // Device state
    QList<DeviceInfo> m_Devices;
    int m_SelectedDeviceIndex;
    QString m_PendingDeviceName;
    SDL_GameController* m_Controller;
    SDL_Joystick* m_Joystick;

    // Binding state
    QMap<int, QString> m_Bindings;         // logicalInputId -> binding string (e.g. "b0", "a1-", "h0.1")
    QMap<int, QString> m_DefaultBindings;  // snapshot taken in open()

    // Capture state
    int m_CapturingInputId;
    int m_CaptureDebounceFrames;
    static const int k_CaptureDebounceFrames = 3;    // ~100ms at 33ms tick
    static const int k_CaptureMaxFrames = 300;        // ~10s at 33ms tick
    int m_CaptureFrameCount;

    // Cached initial axis/button/hat state at capture start
    QMap<int, Sint16> m_InitialAxes;
    QMap<int, Uint8> m_InitialButtons;
    QMap<int, Uint8> m_InitialHats;

    // The 18 standard logical inputs
    static const int k_LogicalInputCount = 18;
};
