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

    ColumnLayout {
        id: gameBoard
        anchors.centerIn: parent
        spacing: 50

        Label {
            id: lblGamePrompt
            anchors.horizontalCenter: parent.horizontalCenter
            text: qsTr("Can You Guess The Word?")
            font.pointSize: 18
        }

        Row {
            anchors.horizontalCenter: parent.horizontalCenter
            spacing: 30
            Rectangle {
                width: 40
                height: 40
                color: "teal"
            }
            Rectangle {
                width: 40
                height: 40
                color: "teal"
            }
            Rectangle {
                width: 40
                height: 40
                color: "teal"
            }
        }

        RowLayout {
            anchors.centerIn: parent.horizontalCenter
            spacing: 30

            ColumnLayout {

                TextField {
                    placeholderText: "Letter Guess"
                    maximumLength: 1
                }

                Label {
                    text: "remaining: 5"
                }
            }

            ColumnLayout {
                Button {
                    text: "Guess Letter"
                }
            }
        }

        WordGuess {}
    }

}
