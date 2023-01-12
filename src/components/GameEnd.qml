import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import QtQuick.Controls.Material


Item {
    anchors.fill: parent

    ColumnLayout {
        anchors.centerIn: parent

        Label {
            anchors.horizontalCenter: parent.horizontalCenter
            font.pointSize: 32
            text: gameState.endGameMessage()
        }

        Button {
            anchors.horizontalCenter: parent.horizontalCenter
            text: "Play Again"
            onClicked: {
                stack.clear()
                stack.push(greetingView)
            }
        }

    }
}
