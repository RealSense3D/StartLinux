import QtQuick 2.0

FocusScope{
    width: 96; height: input.height + 8
    Rectangle{
        anchors.fill: parent
        color: "lightsteelblue"
        border.color: "gray"
    }

    property alias input: input
    property alias text: input.text

    TextInput{
        id: input
        anchors.fill: parent
        anchors.margins: 4
        focus: true
    }
}
