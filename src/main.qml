import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import QtQuick.Controls.Material
import GameManager

import "./components"

ApplicationWindow {
    width: 640
    height: 800
    visible: true
    title: qsTr("Word Guessing Game")
    Material.theme: Material.Dark

    GameManager {
        id: gameManager
    }

    StackView {
        id: stack
        anchors.fill: parent
        initialItem: greetingView
    }

    Component {
        id: greetingView
        GreetingView {}
    }

    Component {
        id: gameBoard

        Column {
            spacing: 25
            padding: 10

            Button {
                text: "Back"
                onClicked: {
                    gameManager.resetGame()
                    stack.pop()
                }
            }

            Label {
                id: lblGamePrompt
                anchors.horizontalCenter: parent.horizontalCenter
                text: qsTr("Can You Guess The Word?")
                font.pointSize: 18
            }

            WordDisplay {}

            LetterGuess {}

            WordGuess {}

            MissedLetters {}

            MissedWords {}
        }
    }

    Component {
        id: gameEndDisplay
        GameEnd {}
    }

}
