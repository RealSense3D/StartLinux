import QtQuick 2.0

Image {
    id: root
    source: "assets/car1.png"
    signal clicked
    property alias text: imageText.text

    MouseArea{
        id: imageMouse
        anchors.fill: parent
        onClicked: root.clicked()
    }
    Text {
        id: imageText
        text: qsTr("text")
        color: "white"
        anchors.top: imageMouse.bottom
        anchors.horizontalCenter: imageMouse.horizontalCenter
    }
}
