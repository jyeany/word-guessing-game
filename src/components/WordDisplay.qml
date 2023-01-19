import QtQuick
import QtQuick.Layouts
import QtQuick.Controls

Row {
    id: letterRow
    anchors.horizontalCenter: parent.horizontalCenter
    spacing: 20

    Repeater {
        id: letterRepeater
        model: gameManager.getChosenLetters()
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
        target: gameManager
        function onLetterGuessesUpdated() {
            const indices = gameManager.currentLetterIndices()
            indices.forEach(i =>
                        letterRepeater
                            .itemAt(i)
                            .children[0]
                            .visible = true)
        }
    }
}
