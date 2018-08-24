import QtQuick 2.0

Item {
    id: root
    width: background.width; height: background.height

    Image {
        id: background
        source: "../assets/black-bg.png"
    }

    MouseArea {
         anchors.fill: parent
         onClicked: {
             rocket1.y = rocket2.y = rocket3.y =root.height - rocket1.height
         }
     }

    ClickImage{
        id: rocket1
        x: 40; y: root.height - rocket1.height
        source: "../assets/car1.png"
        text: "animation on property"
        NumberAnimation on y{
            to: 40
            duration: 4000
        }
//        onClicked: y = 40
    }

    ClickImage{
        id: rocket2
        x: (root.width-width)/2; y: root.height - rocket1.height
        source: "../assets/car1.png"
        text: "behavior on property"
        Behavior on y{
            NumberAnimation{
                duration: 4000
            }
        }
        onClicked: y = 40
    }

    ClickImage{
        id: rocket3
        x: 264; y: 200
        source: "../assets/car1.png"
        onClicked: anim.start()
        text: "standalone animation"

        NumberAnimation{
            id: anim
            target: rocket3
            properties: "y"
            from: 205; to: 40
            duration: 4000
        }
    }

}
