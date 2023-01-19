import QtQuick
import QtQuick.Controls
import QtQuick.Controls.Material

Column {
    id: greetingView
    anchors.horizontalCenter: parent.horizontalCenter
    topPadding: 100
    spacing: 20

    function showGameBoard() {
        stack.push(gameBoard)
    }

    Label {
        anchors.horizontalCenter: parent.horizontalCenter
        font.pointSize: 18
        text: "Please Choose a Difficulty"
    }

    Button {
        id: easyButton
        anchors.horizontalCenter: parent.horizontalCenter
        text: "Easy"
        onClicked: showGameBoard()
    }

    Button {
        anchors.horizontalCenter: parent.horizontalCenter
        text: "Medium"
        onClicked: showGameBoard()
    }

    Button {
        anchors.horizontalCenter: parent.horizontalCenter
        text: "Hard"
        onClicked: showGameBoard()
    }
}
