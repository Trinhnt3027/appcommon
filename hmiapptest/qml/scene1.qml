import QtQuick 2.0
import QtQuick.Controls 2.12

Rectangle {
    id: idScene1
    width: 300
    height: 300
    color: "red"

    Button {
        id: idPopBtn
        width: 100
        height: 50
        anchors.centerIn: parent
        text: "Pop Scene"

        onClicked: {
            console.log("idPopBtn onClicked")
            SceneController.popScene()
        }

        Component.onDestruction: {
            console.log("idPopBtn >> onDestruction")
        }
    }

    Component.onDestruction: {
        console.log("idScene1 >> onDestruction")
    }
}
