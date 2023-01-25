import QtQuick
import QtQuick.Controls
import QtQuick.Controls.Material

Button {
    id: control

    property string btnText
    property color bgColor
    property color hoverColor
    property color pressedColor

    background: Rectangle {
        implicitWidth: 64
        implicitHeight: control.Material.buttonHeight
        radius: 5
        color: parent.down ? pressedColor :
                             (parent.hovered ? hoverColor : bgColor)

        PaddedRectangle {
            y: parent.height - 4
            width: parent.width
            height: 4
            radius: 2
            topPadding: -2
            clip: true
            visible: control.checkable && (!control.highlighted || control.flat)
            color: control.checked && control.enabled ? control.Material.accentColor
                                                      : control.Material.secondaryTextColor
        }

        HoverHandler {
            id: mouse
            acceptedDevices: PointerDevice.Mouse
            cursorShape: Qt.PointingHandCursor
        }

    }
}
