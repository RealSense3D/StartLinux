import QtQuick 2.0


Rectangle{
    id: mySquare
    width: 64; height: this.width
    color: "#ea7025"
    border.color: Qt.lighter(color)
    property alias text: text1.text

    Text {
        id: text1
//        text: qsTr("text")
        anchors.centerIn: parent
        color: "white"

    }
}


