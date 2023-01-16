import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

RowLayout {
    anchors.horizontalCenter: parent.horizontalCenter
    spacing: 30

    ColumnLayout {
        Label {
            text: "Guessed Letters"
            font.pointSize: 18
        }

        Label {
            id: lblGuessedLetters
            font.pointSize: 14
            color: "yellow"
            text: gameState.getGuessedLetters()
        }
    }

    Connections {
        target: gameState
        function onLetterGuessesUpdated() {
            lblGuessedLetters.text = gameState.getGuessedLetters()
        }
    }
}
