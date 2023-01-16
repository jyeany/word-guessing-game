import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import QtQuick.Controls.Material


Item {
    anchors.fill: parent

    ColumnLayout {
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter

        Label {
            Layout.alignment: Qt.AlignHCenter
            font.pointSize: 32
            text: gameState.endGameMessage()

            RotationAnimation on rotation {
                to: 360
                duration: 1000
                running: true
            }
        }

        Button {
            Layout.alignment: Qt.AlignHCenter
            text: "Play Again"
            onClicked: {
                stack.clear()
                stack.push(greetingView)
            }
        }

    }
}
