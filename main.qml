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
            Layout.alignment: Qt.AlignHCenter
            text: qsTr("Can You Guess The Word?")
            font.pointSize: 18
        }

        WordDisplay {}

        LetterGuess {}

        WordGuess {}
    }

}
