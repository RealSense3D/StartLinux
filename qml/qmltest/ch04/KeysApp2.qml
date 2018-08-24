import QtQuick 2.0

DarkSquare{
    width: 400; height: 200

    RedSquare{
        id: square
        x: 8; y: 9
    }
    focus: true
    Keys.onLeftPressed: square.x -= 8
    Keys.onRightPressed: square.x += 8
    Keys.onUpPressed: square.y -= 8
    Keys.onDownPressed: square.y += 8

    MouseArea {
        id: mouseArea
        anchors.fill: parent
        acceptedButtons: Qt.LeftButton | Qt.RightButton
        onClicked: {
            console.log("onClicked")
            if (mouseArea.pressedButtons & Qt.LeftButton){
                square.scale += 0.2
                console.log("LeftButton")
            }
            else if (mouseArea.pressedButtons & Qt.RightButton){
                square.scale -= 0.2
                console.log("RightButton")
            }
        }
    }
    Text {
        id: text1
        color: "white"
        text: mouseArea.pressedButtons & Qt.RightButton ? "right" : ""
    }

    Text {
        id: text2
        color: "white"
        y:10
        text: mouseArea.pressedButtons & Qt.LeftButton ? "left" : ""
    }

    Keys.onPressed: {
        if (event.key & Qt.Key_Left) {
             square.scale *= 1.1
             console.log("boom")
         }
        else if (event.key & Qt.Key_Right) {
            square.scale *= 0.9
            console.log("doom")
        }
    }

    Keys.onSpacePressed: console.log("HELLO")
}
