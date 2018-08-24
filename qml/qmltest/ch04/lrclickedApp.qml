import QtQuick 2.0
// left & right MouseClick
Item {
    id: root
//    width: 500; height: 250
    Rectangle{
        id: buttom
        x:12; y: 12
        width: 116; height: 26
        color: "lightsteelblue"
        border.color: "slategray"
        Text {
            id: text1
            text: qsTr("Start")
            anchors.centerIn: parent
        }
        MouseArea{
            id: mouse1
            anchors.fill: parent
            property int clicknum: 0
            acceptedButtons: Qt.LeftButton | Qt.RightButton
            onClicked:
            {
                status.text = Date().toString()
                if (mouse.button == Qt.LeftButton)
                {
                    clicknum++
                    status.color = "blue"
                }
                else
                {
                    status.color = "red"
                    clicknum--
                }
                text1.text = "Click  " + clicknum
            }
        }
    }



    Text{
        id: status
        anchors{
            horizontalCenter: buttom.horizontalCenter
            top: buttom.bottom
        }
        width: buttom.width; height: buttom.height
        text:"waiting..."
        horizontalAlignment: Text.AlignHCenter
        wrapMode: Text.WordWrap
    }

}
