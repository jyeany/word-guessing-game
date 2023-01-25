import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import QtQuick.Controls.Material

RowLayout {
    anchors.horizontalCenter: parent.horizontalCenter
    spacing: 30

    ColumnLayout {
        Label {
            text: "Missed Words"
            font.pointSize: 18
        }

        Label {
            id: lblMissedWords
            font.pointSize: 14
            color: "yellow"
            text: gameManager.getMissedWords()
        }
    }

    Connections {
        target: gameManager
        function onWordGuessesUpdated() {
            lblMissedWords.text = gameManager.getMissedWords()
        }
    }
}
