import QtQuick 2.0

Rectangle{
    id: root
    width: 136; height: 120
    color: "linen"

    TTextEdit{
        id: input1
        x: 8; y: 8
        width: 120; height: 48
        focus: true
        text: "Text Edit"
        onTextChanged: {
            console.log(text)
        }
    }

    TTextEdit{
        id: input2
        anchors.top: input1.bottom
        anchors.topMargin: 8
        anchors.horizontalCenter: input1.horizontalCenter
        width: 120; height: 48
        focus: true
        text: "Text Edit"
        onTextChanged: {
            console.log(text)
        }
    }
}
