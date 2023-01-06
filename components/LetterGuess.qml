import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import QtQuick.Controls.Material

RowLayout {
    Layout.alignment: Qt.AlignHCenter
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
        Button {
            text: "Guess Letter"
        }
    }
}
