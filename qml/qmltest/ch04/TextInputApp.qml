import QtQuick 2.0

Rectangle {
    id: root
    width: 200; height: 80
    color:"linen"
//    width: bg.width; height: bg.height
//    Image{
//        id: bg
//        source: "assets/black-bg.png"
//    }

    TextInput{
        id: input1
        x: 8; y:8
        width: 96; height: 20
        focus: true
        text:"Text Input 1"
        onTextChanged: {
            console.log("Text1 Changed: " + input1.text)
        }
        KeyNavigation.tab: input2
        selectByMouse: true
    }

    TextInput{
        id: input2
        x: 8; y:36
        width: 96; height: 20
        text:"Text Input 2"
        onTextChanged: {
            console.log("Text2 Changed: " + input2.text)
        }
        KeyNavigation.tab: input1
        selectByMouse: true
    }
}
