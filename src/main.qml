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

    Column {
        id: greetingView
        anchors.horizontalCenter: parent.horizontalCenter
        topPadding: 100
        spacing: 20

        Label {
            anchors.horizontalCenter: parent.horizontalCenter
            font.pointSize: 18
            text: "Please Choose a Difficulty"
        }

        Button {
            id: easyButton
            anchors.horizontalCenter: parent.horizontalCenter
            text: "Easy"
            onClicked: stack.push(gameBoard)
        }

        Button {
            anchors.horizontalCenter: parent.horizontalCenter
            text: "Medium"
            onClicked: stack.push(gameBoard)
        }

        Button {
            anchors.horizontalCenter: parent.horizontalCenter
            text: "Hard"
            onClicked: stack.push(gameBoard)
        }
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

}
