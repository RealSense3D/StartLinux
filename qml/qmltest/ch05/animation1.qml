import QtQuick 2.0

Image {
    id: bg
    source: "../assets/black-bg.png"

    Image {
        id: car
        source: "../assets/car1.png"
        x:0; y: 0

        NumberAnimation on x {
            to: 200
            duration: 4000
            loops: Animation.Infinite
        }

        RotationAnimation on rotation {
            to: 360
            duration: 4000
            loops: Animation.Infinite
        }
    }
}
