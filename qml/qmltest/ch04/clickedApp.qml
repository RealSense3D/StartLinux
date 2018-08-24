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
        MouseArea{
            id: area
            anchors{
                horizontalCenter: rect1.horizontalCenter
                verticalCenter: rect1.verticalCenter
            }
            width: rect1.width
            height: rect1.height
            onClicked: car1.visible =! car1.visible
        }
    }
    Rectangle{
        id: rect2
        anchors{
            left: rect1.right
            leftMargin: 10
            verticalCenter: rect1.verticalCenter
//            top: rect1.top
        }
//        color: "red"
        gradient: Gradient{
            GradientStop{
                position: 0.0;color: "lightsteelblue"
            }
            GradientStop{
                position: 1.0; color: "slategray"
            }
        }

        width: rect1.width; height: rect1.height
        border.color: "lightsteelblue"
        border.width: 4
        radius: 8
        MouseArea{
            id: area2
            anchors{
                horizontalCenter: rect2.horizontalCenter
                verticalCenter: rect2.verticalCenter
            }
            width: rect2.width
            height: rect2.height
            onClicked: car2.visible =! car2.visible
        }
    }
    Text {
        id: text1
        text: qsTr("The quick brown fox")
        color: "#303030"
        font{
            family: "PingFangSC"
            pixelSize: 28
        }
        elide: Text.ElideLeft
        style: Text.Sunken
        styleColor: "red"
        verticalAlignment: Text.AlignTop
    }

    Image {
        id: car1
        source: "assets/car1.png"
        anchors{
            horizontalCenter: rect1.horizontalCenter
            top: rect1.bottom
        }
        width: 50; height: 50
        fillMode: Image.Stretch
    }

    Image {
        id: car2
        source: "assets/car1.png"
        anchors{
            horizontalCenter: rect2.horizontalCenter
            top: rect2.bottom
        }
        width: 50; height: 50
        fillMode: Image.Stretch
    }
}
