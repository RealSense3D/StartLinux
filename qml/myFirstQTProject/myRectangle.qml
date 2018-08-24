import QtQuick 2.0

Item {
    id: myItem
    width: 468
    height: 246
    Rectangle{
        id: myRectangle
        width: myItem.width / 2
        height: myItem.height / 2
        color: "#808080"
        x: myItem.width / 4
        y: myItem.height / 4
    }
}
