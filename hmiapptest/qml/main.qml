import QtQuick 2.12
import QtQuick.Controls 2.12

Rectangle {
    width: 300
    height: 300
    color: "blue"
    opacity: 1

    Button {
        id: idPushBtn
        width: 100
        height: 50
        anchors.centerIn: parent
        text: "Push Scene"

        onClicked: {
            console.log("idPushBtn onClicked")
            SceneController.pushScene("scene1");
        }
    }
}
