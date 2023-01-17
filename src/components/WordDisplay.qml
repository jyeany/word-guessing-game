import QtQuick
import QtQuick.Layouts
import QtQuick.Controls

Row {
    anchors.horizontalCenter: parent.horizontalCenter
    spacing: 20

    Repeater {
        model: gameState.getChosenLetters()
        Rectangle {
            width: 40
            height: 40
            color: "teal"

            Label {
                anchors.centerIn: parent
                font.pointSize: 16
                text: modelData
            }
        }
    }
}
