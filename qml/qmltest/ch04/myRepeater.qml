import QtQuick 2.0

MySquare {
    id: root
    width: 252 * 2+ 16; height: 252 * 2 + 16
    color: "black"
    property variant colorArray: ["#00bde3", "#67c111", "#ea7025"]

    Grid{
        anchors.fill: parent
        anchors.margins: 8
        spacing: 8
        columns: 8
        Repeater {
            model: 64
            Rectangle {
                width: 56; height: 56
                property int colorIndex: Math.floor(Math.random() * 3)
                color: root.colorArray[colorIndex]
                border.color: Qt.lighter(color)
//                Text {
//                    anchors.centerIn: parent
//                    color: "#f0f0f0"
//                    text: "Cell " + index
//                }
                TextInput{
                    anchors.centerIn: parent
                    color: "#f0f0f0"
                    text: "Cell " + index
                    focus: true
                    onTextChanged: {
                        console.log(text)
                    }
                }
            }
        }
    }
}
