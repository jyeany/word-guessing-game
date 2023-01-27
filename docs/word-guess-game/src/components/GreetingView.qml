import QtQuick
import QtQuick.Controls
import QtQuick.Controls.Material
import "./buttons"

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

    ColorButton {
        id: easyButton
        anchors.horizontalCenter: parent.horizontalCenter
        text: "Short (3-5 Letters)"
        bgColor: "#0f7d2c"
        hoverColor: "#36c25b"
        pressedColor: "#67eb8a"
        onClicked: showGameBoard("Short")
    }

    ColorButton {
        anchors.horizontalCenter: parent.horizontalCenter
        text: "Medium (5-8 Letters)"
        bgColor: "#ada91d"
        hoverColor: "#d1cc38"
        pressedColor: "#e6e155"
        onClicked: showGameBoard("Medium")
    }

    ColorButton {
        anchors.horizontalCenter: parent.horizontalCenter
        text: "Long (Over 8 Letters)"
        bgColor: "#9c2e10"
        hoverColor: "#b33917"
        pressedColor: "#d14e2a"
        onClicked: showGameBoard("Long")
    }
}
