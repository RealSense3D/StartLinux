import QtQuick 2.0

Item {
    Buttom{
        id: buttom
        x:12; y:12
        text: "Start"
        property int clicknum: 0
        onClicked: {
            clicknum++
            this.border.color = "red"
            this.text = "oleole!"
            status.text = "Click " + clicknum
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
