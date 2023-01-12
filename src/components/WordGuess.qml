import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import QtQuick.Controls.Material

RowLayout {
    anchors.horizontalCenter: parent.horizontalCenter
    spacing: 30

    ColumnLayout {

        TextField {
            id: txtWordGuess
            placeholderText: "Word Guess"
        }

        Label {
            id: lblWordGuessRemaining
            text: "remaining: " + gameState.getWordGuesses()
        }

    }

    Button {
        id: btnGuessWord
        text: "Guess Word"
        onClicked: {
            const correct = gameState.makeWordGuess(txtWordGuess.text)
            if (!correct) {
                lblWordGuessRemaining.text = "remaining: " + gameState.getWordGuesses()
                const remaining = gameState.getWordGuesses();
                if (remaining === 0) {
                    stack.push(gameEndDisplay)
                }
            } else {
                stack.push(gameEndDisplay)
            }
        }
    }
}
