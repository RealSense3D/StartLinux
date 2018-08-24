import QtQuick 2.0

ClickImage{
    id: rocket2
    x: 152; y: 200
    width: 1023; height: 600
    source: "../assets/car1.png"
    text: "behavior on property"
    Behavior on y{
        NumberAnimation{
            duration: 400
        }
    }

    clicked: y = 40
}
