import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.0

Item {
    visible: true
    width: 800
    height: 800
//    title: qsTr("Hello World")

    // https://doc.qt.io/archives/qt-5.5/qml-qtquick-text.html#baseUrl-prop
    Text {
        id: lettle_Hello_1
        text: "h"
        font.pixelSize: 120
        font.capitalization: Font.Capitalize
        styleColor: "#ff00ff"
        style: Text.Sunken
        color: "#3cba54"

        x: 50
        y: x / 2
    }

    Text {
        id: lettle_Hello_2
        text: qsTr("E")
        color: "#f4c20d"
        font.pixelSize: lettle_Hello_1.font.pixelSize - 20

        anchors.left: lettle_Hello_1.right
        anchors.top: lettle_Hello_1.bottom

    }

    Text {
        id: lettle_Hello_3
        text: qsTr("l")
        color: "#db3236"
        font.capitalization: Font.AllUppercase

        font.pixelSize: lettle_Hello_2.font.pixelSize - 8

        anchors.left: lettle_Hello_2.right
        anchors.top: lettle_Hello_2.bottom
    }

    Text {
        id: lettle_Hello_4
        text: qsTr("L")
        color: "#db3236"
        font.pixelSize: lettle_Hello_3.font.pixelSize - 6

        anchors.left: lettle_Hello_3.right
        anchors.top: lettle_Hello_3.bottom
    }

    Text {
        id: lettle_Hello_5
        text: qsTr("o")
        color: "#4885ed"
        font.pixelSize: lettle_Hello_4.font.pixelSize - 4
        anchors.left: lettle_Hello_4.right
        anchors.top: lettle_Hello_4.bottom
    }

    Text {
        id: lettle_Dot
        text: qsTr("Xd")
        color: "#808080"
        font.pixelSize: lettle_Hello_5.font.pixelSize - 2
        anchors.left: lettle_Hello_5.right
        anchors.top: lettle_Hello_5.bottom
    }

    Text {
        id: lettle_Kitty_1
        text: qsTr("K")
        color: "#4885ed"
        font.pixelSize: lettle_Dot.font.pixelSize + 2
        anchors.left: lettle_Dot.right
        anchors.bottom: lettle_Dot.top
    }

    Text {
        id: lettle_Kitty_2
        text: qsTr("I")
        color: "#db3236"
        font.pixelSize: lettle_Kitty_1.font.pixelSize  + 4
        font.capitalization: Font.AllLowercase
        anchors.left: lettle_Kitty_1.right
        anchors.bottom: lettle_Kitty_1.top
    }

    Text {
        id: lettle_Kitty_3
        text: qsTr("T")
        color: "#f4c20d"
        font.pixelSize: lettle_Kitty_2.font.pixelSize  + 6
        anchors.left: lettle_Kitty_2.right
        anchors.bottom: lettle_Kitty_2.top
    }

    Text {
        id: lettle_Kitty_4
        text: qsTr("T")
        color: "#f4c20d"
        font.pixelSize: lettle_Kitty_3.font.pixelSize + 8
        anchors.left: lettle_Kitty_3.right
        anchors.bottom: lettle_Kitty_3.top
    }

    Text {
        id: lettle_Kitty_5
        text: qsTr("Y")
        styleColor: "#ff00ff"
        style: Text.Sunken
        color: "#3cba54"
        clip :true

        font.pixelSize: lettle_Kitty_4.font.pixelSize + 20
        anchors.left: lettle_Kitty_4.right
        anchors.bottom: lettle_Kitty_4.top
    }
/*
    Rectangle{
        x: lettle_Hello_1.x
        y: lettle_Hello_1.y + lettle_Hello_1.paintedHeight
        width: lettle_Kitty_5.x - lettle_Hello_1.x + lettle_Kitty_5.paintedWidth
        height: 10
        color: "black"
    }
*/
}
