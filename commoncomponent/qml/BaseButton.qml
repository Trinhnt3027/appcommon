import QtQuick 2.12

Rectangle {
    id: root

    property string textContent: idText.text

    signal pressed()
    signal released()
    signal clicked()

    width: 100
    height: 100
    border.width: 1
    color: {
        if (idMouseArea.containsPress) return "#C2C2C2"
        if (idMouseArea.containsMouse) return "#ECECEC"
        return "#FFFFFF"
    }

    Text {
        id: idText
        text: textContent
        clip: true
        anchors {
            left: root.left
            leftMargin: 10
            right: root.right
            rightMargin: 10
            top: root.top
            topMargin: 10
            bottom: root.bottom
            bottomMargin: 10
        }
        wrapMode: Text.WordWrap
        font.pixelSize: 20
        color: "#000000"
        elide: Text.ElideRight
        horizontalAlignment: Text.AlignLeft
        verticalAlignment: Text.AlignVCenter
    }

    MouseArea {
        id: idMouseArea
        anchors.fill: parent
        cursorShape: Qt.PointingHandCursor
        hoverEnabled: true

        onPressed: {
            root.pressed()
        }

        onReleased: {
            root.released()
        }

        onClicked: {
            root.clicked()
        }
    }
}
