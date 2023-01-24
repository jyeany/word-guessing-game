import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import QtQuick.Controls.Material

RowLayout {
    anchors.horizontalCenter: parent.horizontalCenter
    spacing: 30

    function performWordGuess() {
        const correct = gameManager.makeWordGuess(txtWordGuess.text)
        if (!correct) {
            lblWordGuessRemaining.text = "remaining: " + gameManager.getWordGuesses()
            const remaining = gameManager.getWordGuesses();
            if (remaining === 0) {
                stack.push(gameEndDisplay)
            }
        } else {
            stack.push(gameEndDisplay)
        }
    }

    ColumnLayout {

        TextField {
            id: txtWordGuess
            placeholderText: "Word Guess"
            onAccepted: performWordGuess()
        }

        Label {
            id: lblWordGuessRemaining
            text: "remaining: " + gameManager.getWordGuesses()
        }

    }

    Button {
        id: btnGuessWord
        text: "Guess Word"
        onClicked: performWordGuess()
    }
}
