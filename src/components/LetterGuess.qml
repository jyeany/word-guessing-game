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
            focus: true
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
                    const remaining = gameState.getLetterGuesses()
                    if (remaining === 0) {
                        stack.push(gameEndDisplay)
                    } else {
                        lblLetterGuess.text =
                                "remaining: " + gameState.getLetterGuesses()
                    }
                } else {
                    const gameMode = gameState.getGameModeStr()
                    console.log(gameMode)
                    if (gameMode === "won") {
                        stack.push(gameEndDisplay)
                    }
                }
                txtLetterGuess.text = ""
                txtLetterGuess.focus = true
            }
        }
    }
}
