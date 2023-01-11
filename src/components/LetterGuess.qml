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
            placeholderText: "Letter Guess"
            maximumLength: 1
        }

        Label {
            text: "remaining: 5"
        }
    }

    ColumnLayout {
        id: guessLetterLayout
        Button {
            id: btnGuessLetter
            text: "Guess Letter"

            SignalSpy {
                id: clickSpy
                target: btnGuessLetter
                signalName: "btnGuessLetterClicked"
            }

            TestCase {
                name: "Guess Letter Click"
                function test_click() {
                    compare(clickSpy.count, 0)
                    btnGuessLetter.clicked()
                    compare(clickSpy.count, 1)
                }
            }
        }
    }
}
