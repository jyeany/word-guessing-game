import QtQuick
import QtTest
import QtQuick.Controls
import QtQuick.Layouts
import QtQuick.Controls.Material

RowLayout {
    id: guessLetterRowLayout
    anchors.horizontalCenter: parent.horizontalCenter
    spacing: 30

    ColumnLayout {

        TextField {
            id: txtLetterGuess
            placeholderText: "Letter Guess"
            maximumLength: 1
        }

        Label {
            id: lblLetterGuess
            text: "remaining: " + gameState.getLetterGuesses()
        }
    }

    ColumnLayout {
        id: guessLetterLayout
        Button {
            id: btnGuessLetter
            text: "Guess Letter"
            onClicked: {
                const found = gameState.makeLetterGuess(txtLetterGuess.text)
                if (!found) {
                    lblLetterGuess.text =
                            "remaining: " + gameState.getLetterGuesses()
                }
            }
        }
    }
}
