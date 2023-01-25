import QtQuick
import QtQuick.Controls
import QtQuick.Controls.Material

Column {
    id: greetingView
    anchors.horizontalCenter: parent.horizontalCenter
    topPadding: 100
    spacing: 20

    function showGameBoard(wordLength) {
        gameManager.createGame(wordLength)
        stack.push(gameBoard)
    }

    Label {
        anchors.horizontalCenter: parent.horizontalCenter
        font.pointSize: 18
        text: "Please Choose a Word Length"
    }

    Button {
        id: easyButton
        anchors.horizontalCenter: parent.horizontalCenter
        text: "Short (3-5 Letters)"
        background: Rectangle {
                color: parent.down ? "white" :
                        (parent.hovered ? "gray" : "green")
        }
        onClicked: showGameBoard("Short")
    }

    Button {
        anchors.horizontalCenter: parent.horizontalCenter
        text: "Medium (5-8 Letters)"
        onClicked: showGameBoard("Medium")
    }

    Button {
        anchors.horizontalCenter: parent.horizontalCenter
        text: "Long (Over 8 Letters)"
        onClicked: showGameBoard("Long")
    }
}
