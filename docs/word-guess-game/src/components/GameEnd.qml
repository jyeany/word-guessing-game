import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import QtQuick.Controls.Material


Item {
    anchors.fill: parent

    ColumnLayout {
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter
        spacing: 15

        Label {
            Layout.alignment: Qt.AlignHCenter
            font.pointSize: 32
            text: gameManager.endGameMessage()

            RotationAnimation on rotation {
                to: 360
                duration: 1000
                running: true
            }
        }

        Label {
            Layout.alignment: Qt.AlignHCenter
            font.pointSize: 24
            text: "The Word Was:"
        }

        Label {
            Layout.alignment: Qt.AlignHCenter
            font.pointSize: 32
            color: "yellow"
            text: gameManager.getSolutionWord()
        }

        Button {
            Layout.alignment: Qt.AlignHCenter
            text: "Play Again"
            onClicked: {
                stack.clear()
                stack.push(greetingView)
            }

            HoverHandler {
                id: mouse
                acceptedDevices: PointerDevice.Mouse
                cursorShape: Qt.PointingHandCursor
            }
        }

    }
}
