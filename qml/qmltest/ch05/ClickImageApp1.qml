import QtQuick 2.0

ClickImage{
    id: rocket1
    x: 40; y: 200
    source: "../assets/car1.png"
    text: "animation on property"
    NumberAnimation on y{
        to: 40
        duration: 4000
    }
}
