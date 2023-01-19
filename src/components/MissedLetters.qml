import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import QtQuick.Controls.Material

RowLayout {
    anchors.horizontalCenter: parent.horizontalCenter
    spacing: 30

    ColumnLayout {
        Label {
            text: "Missed Letters"
            font.pointSize: 18
        }

        Label {
            id: lblGuessedLetters
            font.pointSize: 14
            color: "yellow"
            text: gameManager.getGuessedLetters()
        }
    }

    Connections {
        target: gameManager
        function onLetterGuessesUpdated() {
            lblGuessedLetters.text = gameManager.getGuessedLetters()
        }
    }
}
