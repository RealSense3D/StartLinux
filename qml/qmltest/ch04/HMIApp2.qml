import QtQuick 2.0

Item {
    property bool isTurnLeft: true
    property bool isTurnRight: false


    id: myItem
    width: 1024
    height: 600

    /*********************************************/
    Rectangle{
        id: mappppp
        width: 420
        height: 600
        gradient: Gradient{
            GradientStop{ position: 0.0; color: "#000000"}
            GradientStop{ position: 0.2; color: "#808080"}
            GradientStop{ position: 0.4; color: "#3cba54"}
            GradientStop{ position: 0.6; color: "#f4c20d"}
            GradientStop{ position: 0.8; color: "#db3236"}
            GradientStop{ position: 1.0; color: "#4885ed"}
        }
        x: 604
        y: 0
    }

    Image {
        id: navigation
        source: "assets/navigation.png"
        property int xd: 799
        property int yd: 272
        x: xd
        y: yd
        width: 116
        height: 116
        rotation: 45
    }

    Image {
        id: navigation2
        source: "assets/navigation.png"
        anchors{
            horizontalCenter: navigation.horizontalCenter
            top: navigation.bottom
        }
        rotation: 45
        scale: 1.5
//        transformOrigin: 0
//        transform:
    }

    Timer{
        id: timenowTimer
        interval: 100; running: true; repeat: true
        onTriggered: timenow.text = Date().toLocaleString(Qt.locale("zh_CN"))
    }

    Text {
        id: timenow
//        text: Date().toLocaleString(Qt.locale("zh_CN"))
        anchors{
            right: myItem.right
        }

        y: 10
        font{
            family: "PingFangSC"
            weight: "Medium"
            pixelSize: 14
            letterSpacing: 0.07
        }
        color: "#cccccc"
        lineHeight: 20
    }

    Image {
        id: pPin
        source: "assets/P.png"
        x: 744
        y: 62
        width: 11
        height: 14
    }

    Image {
        id: rPin
        source: "assets/R.png"
        anchors{
            left: pPin.right
            bottom: pPin.bottom
            leftMargin: 13
        }
    }

    Image {
        id: nPin
        source: "assets/N.png"
        anchors{
            left: rPin.right
            bottom: rPin.bottom
            leftMargin: 13
        }
    }

    Image {
        id: dPin
        source: "assets/D.png"
        anchors{
            left: nPin.right
            bottom: nPin.bottom
            leftMargin: 13
        }
    }

    Image {
        id: temp
        source: "assets/temperature.png"
        anchors{
            left: dPin.right
            bottom: dPin.bottom
            leftMargin: 26
        }
    }

    Text {
        id: tempvalueText
        property int watertempval: 90
        text: watertempval + qsTr("°C")
        anchors{
            left: temp.right
            bottom: temp.bottom
            leftMargin: 13
        }
        font{
            family: "PingFangSC"
            weight: "Medium"
            pixelSize: 20
            letterSpacing: 0.1
        }
        color: "#808080"
    }
    property int oilNum: 0

    Timer{
        id: oilTimer
        interval: 100; running: true; repeat: true
        onTriggered: oilNum = (oilNum+1)%100
    }

    Image {
        id: oil
        source: if(oilNum >= 90)
                    return "assets/oil1.png"
                else if(oilNum >= 50)
                    return "assets/oil2.png"
                else if(oilNum >= 25)
                    return "assets/oil3.png"
                else if(oilNum >= 15)
                    return "assets/oil4.png"
                else if(oilNum >= 10)
                    return "assets/oil5.png"
                else
                    return "assets/oil6.png"

        anchors{
            left: tempvalueText.right
            bottom: tempvalueText.bottom
            leftMargin: 13
        }
    }

    /************************************/
    Image {
        id: black_bg
        source: "assets/black-bg.png"
        width: 720
        height: 600
        x: 0
        y: 0
    }

    Text {
        id: speedview
        property int speed: 67
        text: speed
        width: 66
        height: 78
        anchors.horizontalCenter: black_bg.horizontalCenter
        anchors.top: black_bg.top
        anchors.topMargin: 15
        font{
            family: "PingFangSC"
            weight: "Medium"
            pixelSize: 56
            letterSpacing: 0.31
        }
        color: "#ffffff"
        lineHeightMode: Text.FixedHeight
        lineHeight: 78
    }

    Text {
        id: speedunit
        text: qsTr("km/h")
        anchors{
            horizontalCenter: speedview.horizontalCenter
            top: speedview.bottom
            topMargin: -15
        }
        font{
            family: "PingFangSC"
            weight: "Medium"
            pixelSize: 18
            letterSpacing: 0.1
        }
        color: "#7a7a7a"
        lineHeightMode: Text.FixedHeight
        lineHeight: 25
    }

    Timer{
        id: turnleftTimer
        interval: 500;running: isTurnLeft;repeat: true
        onTriggered: turnleft.visible = !turnleft.visible
    }
    Timer{
        id: turnRightTimer
        interval: 500;running: isTurnRight;repeat: true
        onTriggered: turnright.visible = !turnright.visible
    }

    Image {
        id: turnleft
        source: switch(isTurnLeft){
                case true: return "assets/Turnleft1.png"
                default: return "assets/Turnleftgray1.png"
                }
        anchors{
            right: speedview.left
            rightMargin: 20
            verticalCenter: speedview.verticalCenter
        }
        width: 75
        height: 61
        opacity: switch(isTurnLeft){
                     case true: return 1
                     default: return 0.47
                     }
    }

    Image {
        id: turnright
        source: switch(isTurnRight){
                case true: return "assets/Turnright1.png"
                default: return "assets/Turnrightgray1.png"
                }
        anchors{
            left: speedview.right
            leftMargin: 20
            verticalCenter: speedview.verticalCenter
        }
        width: 75
        height: 61
        opacity: switch(isTurnRight){
                     case true: return 1
                     default: return 0.47
                     }
    }

    Image {
        id: redlight
        source: "assets/redlight.png"
        anchors{
            left: black_bg.left
            verticalCenter: speedview.verticalCenter
        }
        width: 157
        height: 87
    }

    Text {
        id: lighttime
        text: qsTr("28")
        anchors{
            right: redlight.right
            verticalCenter: redlight.verticalCenter
            rightMargin: 15
        }
        font{
            family: "PingFangSC"
            weight: "Medium"
            pixelSize: 36
            letterSpacing: 0.2
        }
        color: "#808080"
    }

    Text {
        id: warnText
        text: qsTr("左前方车辆相向而行")
        anchors{
            top: speedunit.bottom
            horizontalCenter: black_bg.horizontalCenter
        }
        font{
            family: "PingFangSC"
            weight: "Medium"
            pixelSize: 26
            letterSpacing: 0.1
        }
        opacity: 0.6368
        color: "#ffffff"
        lineHeight: 37
    }

    Image {
        id: road
        source: "assets/road.png"
        anchors{
            bottom: black_bg.bottom
            horizontalCenter: black_bg.horizontalCenter
        }
    }

    Image {
        id: mycar
        source: "assets/car1.png"
        anchors{
            verticalCenter: road.verticalCenter
            horizontalCenter: road.horizontalCenter
            verticalCenterOffset: 61.8
        }
    }

    Image {
        id: hiscar
        source: "assets/car1.png"
        anchors{
            horizontalCenter: mycar.horizontalCenter
            bottom: mycar.top
            bottomMargin: 50
        }
        opacity: 0.69
        width: mycar.width * 0.7
        height: mycar.height * 0.7
    }

    Image {
        id: youcar
        source: "assets/car2.png"
        anchors{
            right: hiscar.left
            bottom: hiscar.top
        }
        scale: 0.7
        rotation: 15
    }
    Image {
        id: warning2
        source: "assets/warning2.png"
        anchors{
            horizontalCenter: youcar.horizontalCenter
            verticalCenter: youcar.verticalCenter
        }
    }
    Rectangle{
        id: distline
        width: 70
        height: 2
        anchors{
            right: youcar.horizontalCenter
            top: youcar.bottom
            topMargin: -10
        }
        color: "yellow"
    }
    Text {
        id: distview
        property int distval: 50
        text: distval + qsTr("m")
        anchors{
            right: distline.left
            verticalCenter: distline.verticalCenter
        }
        font{
            pixelSize: 30
            family: "PingFangSC"
            weight: "Medium"
            letterSpacing: 0.16
        }
        color: "white"
    }

    Image {
        id: steeringwheel
        source: "assets/steeringwheel.png"
        x: 31
        y: 502
    }

    Image {
        id: speedlimit
        source: "assets/speedlimit.png"
        anchors{
            horizontalCenter: steeringwheel.horizontalCenter
            bottom: steeringwheel.top
            bottomMargin: 50
        }
    }
    Image {
        id: watchfochild
        source: "assets/WatchforChildren.png"
        anchors{
            horizontalCenter: speedlimit.horizontalCenter
            bottom: speedlimit.top
            bottomMargin: 50
        }
    }
    Text {
        id: distwatchfochild
        property int distval: 60
        text: distval + qsTr("m")
        anchors{
            top: watchfochild.bottom
            horizontalCenter: watchfochild.horizontalCenter
        }
        font{
            family: "PingFangSC"
            weight: "Medium"
            pixelSize: 16
        }
        color: "#ffffff"
    }

}
