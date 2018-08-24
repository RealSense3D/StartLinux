import QtQuick 2.0

Rectangle {
    id: root
    width: 200; height: 104
    color:"linen"

    TLineEditV2{
        id: input1
        x: 8; y: 8
        input.height: 32
        text:""
        onTextChanged: {
            console.log("Text1: " + input1.text)
        }
        KeyNavigation.tab: input2
    }
    TLineEditV2{
        id: input2
        x: 8; y: 56
        input.height: 32
        text:""
        onTextChanged: {
            console.log("Text2: " + input2.text)
        }
        KeyNavigation.tab: input1
    }
    ListElement {

    }
}
