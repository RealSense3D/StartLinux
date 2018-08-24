import QtQuick 2.5

Item {
    id: root
    width: background.width; height: background.height

    Image {
        id: background
        source: "../assets/black-bg.png"
    }


    //M4>>
    MouseArea {
        anchors.fill: parent
        onClicked: {
            greenBox.y = blueBox.y = redBox.y = background.height - greenBox.height
        }
    }
    //<<M4

    //M1>>
    ClickImage {
        id: greenBox
        x: 40; y: root.height-height
        source: "../assets/car1.png"
        text: "animation on property"
        NumberAnimation on y {
            to: 40; duration: 4000
        }
    }
    //<<M1

    //M2>>
    ClickImage {
        id: blueBox
        x: (root.width-width)/2; y: root.height-height
        source: "../assets/car1.png"
        text: "behavior on property"
        Behavior on y {
            NumberAnimation { duration: 4000 }
        }

        onClicked: y = 40
        // random y on each click
//        onClicked: y = 40+Math.random()*(205-40)
    }
    //<<M2

    //M3>>
    ClickImage {
        id: redBox
        x: root.width-width-40; y: root.height-height
        source: "../assets/car1.png"
        onClicked: anim.start()
//        onClicked: anim.restart()

        text: "standalone animation"

        NumberAnimation {
            id: anim
            target: redBox
            properties: "y"
            to: 40
            duration: 4000
        }
    }
    //<<M3

}
