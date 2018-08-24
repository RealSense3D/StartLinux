import QtQuick 2.0
//testRectangle.qmltestRectangle.qml
Item {
    id: root
    width: 500; height: 250
    Rectangle{
        id: rect1
        x: 112; y: 12
        width: 76; height: 96
        color: "lightsteelblue"
    }
    Rectangle{
        id: rect2
        anchors{
            left: rect1.right
            leftMargin: 10
            verticalCenter: rect1.verticalCenter
//            top: rect1.top
        }
        color: "red"
        width: rect1.width; height: rect1.height
        border.color: "lightsteelblue"
        border.width: 4
        radius: 8
    }
}
