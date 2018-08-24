import QtQuick 2.0


Rectangle{
    id: root
    x:12; y: 12
    width: 116; height: 26
    color: "lightsteelblue"
    border.color: "slategray"
    property alias text: text1.text
    property alias mouse: mouse1.left
    signal clicked
    Text {
        id: text1
        text: qsTr("Start")
        anchors.centerIn: parent
    }
    MouseArea{
        id: mouse1
        anchors.fill: parent
        acceptedButtons: Qt.LeftButton | Qt.RightButton

        onClicked:
        {
            root.clicked()

        }
    }
}

