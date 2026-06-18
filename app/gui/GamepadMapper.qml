import QtQuick 2.9
import QtQuick.Controls 2.2
import QtQuick.Layouts 1.3

import GamepadMapperManager 1.0

Item {
    objectName: qsTr("Gamepad Mapping")

    property int selectedDeviceIndex: -1
    property int capturingInputId: -1
    property int bindingsRev: 0

    // Error dialog for the page
    NavigableMessageDialog {
        id: errorDialog
        standardButtons: Dialog.Ok
    }

    StackView.onActivated: {
        GamepadMapperManager.open()
        GamepadMapperManager.rescan()
    }

    StackView.onDeactivating: {
        GamepadMapperManager.close()
    }

    ColumnLayout {
        anchors.fill: parent
        anchors.margins: 16
        spacing: 12

        Label {
            text: qsTr("Gamepad Mapper")
            font.pointSize: 18
            font.bold: true
        }

        // Device selector row
        Row {
            id: deviceRow
            spacing: 8
            Layout.fillWidth: true
            Layout.preferredHeight: 40

            Repeater {
                model: GamepadMapperManager.attachedDevices

                delegate: Rectangle {
                    id: deviceDelegate
                    height: 36
                    width: deviceLabel.width + (trashBtn.visible ? trashBtn.width + 4 : 20)
                    radius: 4
                    border.color: index == selectedDeviceIndex ? "purple" : "#555"
                    border.width: index == selectedDeviceIndex ? 2 : 1
                    color: index == selectedDeviceIndex ? "#2a0040" : "#333"

                    Row {
                        spacing: 4
                        anchors.verticalCenter: parent.verticalCenter
                        anchors.left: parent.left
                        anchors.leftMargin: 8

                        Label {
                            id: deviceLabel
                            text: modelData.name + (modelData.mapped ? "" : " *")
                            color: "white"
                            anchors.verticalCenter: parent.verticalCenter
                        }

                        Button {
                            id: trashBtn
                            text: "✕"
                            visible: modelData.userSaved
                            flat: true
                            implicitWidth: 22
                            implicitHeight: 22
                            anchors.verticalCenter: parent.verticalCenter
                            font.pixelSize: 10
                            onClicked: {
                                GamepadMapperManager.deleteMappingForDevice(modelData.guid)
                            }
                        }
                    }

                    MouseArea {
                        anchors.fill: parent
                        onClicked: {
                            selectedDeviceIndex = index
                            GamepadMapperManager.selectDeviceByIndex(index)
                        }
                    }
                }
            }

            Label {
                text: qsTr("(No gamepads detected)")
                visible: GamepadMapperManager.attachedDevices.length === 0
                color: "#888"
                anchors.verticalCenter: parent.verticalCenter
            }
        }

        // Binding list header
        RowLayout {
            Layout.fillWidth: true
            Layout.preferredHeight: 24

            Label { text: qsTr("Input"); font.bold: true; Layout.preferredWidth: 100 }
            Label { text: qsTr("Binding"); font.bold: true; Layout.fillWidth: true }
            Label { text: ""; Layout.preferredWidth: 160 }
        }

        // Binding list
        Flickable {
            Layout.fillWidth: true
            Layout.fillHeight: true
            contentHeight: bindingColumn.height
            clip: true
            boundsBehavior: Flickable.OvershootBounds

            ScrollBar.vertical: ScrollBar {}

            Column {
                id: bindingColumn
                width: parent.width
                spacing: 4

                Repeater {
                    model: GamepadMapperManager.logicalInputs()

                    delegate: Rectangle {
                        width: parent.width
                        height: 36
                        radius: 3
                        color: "#2a2a2a"

                        RowLayout {
                            anchors.fill: parent
                            anchors.margins: 8
                            spacing: 8

                            Label {
                                text: modelData.label
                                color: "white"
                                font.bold: true
                                Layout.preferredWidth: 100
                            }

                            Label {
                                text: {
                                    bindingsRev;
                                    return GamepadMapperManager.currentBindingDescription(modelData.id);
                                }
                                color: {
                                    bindingsRev;
                                    return (GamepadMapperManager.currentBindingDescription(modelData.id) === qsTr("(unbound)")) ? "#888" : "#4caf50";
                                }
                                Layout.fillWidth: true
                                elide: Text.ElideRight
                            }

                            Button {
                                text: capturingInputId === modelData.id
                                      ? qsTr("Press a button or move a stick...")
                                      : qsTr("Listen")
                                implicitWidth: capturingInputId === modelData.id ? 220 : 80
                                enabled: selectedDeviceIndex >= 0 && capturingInputId !== modelData.id
                                onClicked: {
                                    capturingInputId = modelData.id
                                    GamepadMapperManager.startCapture(modelData.id)
                                }
                            }

                            Button {
                                text: qsTr("Clear")
                                enabled: selectedDeviceIndex >= 0 && capturingInputId !== modelData.id
                                onClicked: {
                                    GamepadMapperManager.clearBinding(modelData.id)
                                    bindingsRev++
                                }
                            }
                        }
                    }
                }
            }
        }

        // Bottom actions
        RowLayout {
            Layout.fillWidth: true
            spacing: 8

            Item { Layout.fillWidth: true }

            Button {
                text: qsTr("Reset to default")
                enabled: selectedDeviceIndex >= 0
                onClicked: {
                    GamepadMapperManager.resetToDefault()
                    bindingsRev++
                }
            }

            Button {
                text: qsTr("Cancel")
                onClicked: StackView.view.pop()
            }

            Button {
                text: qsTr("Save")
                enabled: selectedDeviceIndex >= 0
                highlighted: true
                onClicked: {
                    GamepadMapperManager.commitMapping()
                    StackView.view.pop()
                }
            }
        }
    }

    Connections {
        target: GamepadMapperManager
        function onBindingCaptured(id, binding) {
            capturingInputId = -1
            bindingsRev++
        }
        function onCaptureTimeout() {
            capturingInputId = -1
        }
        function onErrorOccurred(msg) {
            errorDialog.text = msg
            errorDialog.open()
        }
        function onMappingCommitted() {
            // Re-scan to update device list
            GamepadMapperManager.rescan()
        }
    }
}

