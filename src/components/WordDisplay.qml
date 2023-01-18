import QtQuick
import QtQuick.Layouts
import QtQuick.Controls

Row {
    id: letterRow
    anchors.horizontalCenter: parent.horizontalCenter
    spacing: 20

    Repeater {
        id: letterRepeater
        model: gameState.getChosenLetters()
        Rectangle {
            width: 40
            height: 40
            color: "teal"

            Label {
                anchors.centerIn: parent
                font.pointSize: 16
                text: modelData
                visible: false
            }
        }
    }

    Connections {
        target: gameState
        function onLetterGuessesUpdated() {
            const indices = gameState.currentLetterIndices()
            indices.forEach(i =>
                        letterRepeater
                            .itemAt(i)
                            .children[0]
                            .visible = true)
        }
    }
}
