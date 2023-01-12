import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import QtQuick.Controls.Material
import GameState

import "./components"

ApplicationWindow {
    width: 640
    height: 480
    visible: true
    title: qsTr("Word Guessing Game")
    Material.theme: Material.Dark

    GameState {
        id: gameState
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
            anchors.horizontalCenter: parent.horizontalCenter
            spacing: 25
            padding: 10

            Button {
                text: "Back"
                onClicked: stack.pop()
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
        }
    }

    Component {
        id: gameEndDisplay
        GameEnd {}
    }

}
