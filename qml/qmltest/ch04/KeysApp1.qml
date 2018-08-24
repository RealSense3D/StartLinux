import QtQuick 2.0

DarkSquare{
    width: 400; height: 200

    RedSquare{
        id: square
        x: 8; y: 9
        smooth: true
    }
    RedSquare{
        id: square1
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter
    }
    focus: true
    Keys.onLeftPressed: square.x -= 8
    Keys.onRightPressed: square.x += 8
    Keys.onUpPressed: square.y -= 8
    Keys.onDownPressed: square.y += 8
    Keys.onPressed: {
        switch(event.key){
        case Qt.Key_Plus:
            square.scale += 0.2
            square1.scale += 0.2
            break;
        case Qt.Key_Minus:
            square.scale -= 0.2
            square1.scale -= 0.2
            break;
        case Qt.Key_M:
            square.rotation -= 2
            square1.rotation -= 2
            console.log("%x", Qt.Key_M)
            break;
        case Qt.Key_N:
            square.rotation += 2
            square1.rotation += 2
            break;
        }
    }
}
