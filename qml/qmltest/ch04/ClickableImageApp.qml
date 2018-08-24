import QtQuick 2.0
// MouseClick  & Componentents


Item {
    id: root
    width: bg.width; height: bg.height
    Image {
        id: bg
        source: "assets/black-bg.png"
    }

    MouseArea{
        id: bgClicker
        anchors.fill: parent
        onClicked:
        {
            car1.y = 40
            car2.scale = 1
            car2.rotation = 0
            car3.scale = 1
            car3.rotation = 0
        }
    }

    ClickableImage{
        id: car1
        x: 20; y: 40
        source: "assets/car1.png"
        smooth: true
        onClicked:
        {
            y += 5
            console.log("car1 y = ", y)
        }
        text: "car1"
    }
    ClickableImage{
        id: car2
        x: 170; y: 40
        smooth: true
        source: "assets/car1.png"
        onClicked: {
            scale *= 0.85
            rotation += 5
            console.log("car2 scale = ", scale)
            console.log("car2 rotation = ", rotation)
        }
        text: "car2"
    }
    ClickableImage{
        id: car3
        x: 320; y: 40
        smooth: true
        source: "assets/car1.png"
        onClicked: {
            scale += 0.05
            rotation += 5
            console.log("car3 scale = ", scale)
            console.log("car3 rotation = ", rotation)
        }
        text: "car3"
    }
}
