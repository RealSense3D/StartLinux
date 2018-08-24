import QtQuick 2.0
import QtLocation 5.6
import QtPositioning 5.6


Rectangle {
    width: 1024
    height:600
    color: "#000000"
    property int type: 2
    property int windtype: 1
    property int a: 1
    Map {
        property int loopa: 0
        id:map
        width: parent.width /2
        height: parent.height /2
        anchors.centerIn: parent
        scale: 2
        plugin: osmPlugin
        center: QtPositioning.coordinate(nfLtevDisplay.vLAT,nfLtevDisplay.vLONG-0.0006) // Oslo
        zoomLevel: 16
        activeMapType: supportedMapTypes[2]
        color: "black"
        MapQuickItem{
            id: marker
            anchorPoint.x: image.width/2
            anchorPoint.y: image.height/2
            rotation: nfLtevDisplay.heading
            transformOrigin: Item.Center
            scale: 0.5
            sourceItem: Image {
                id: image

                source: "assets/navigation.png"
            }
            coordinate:  QtPositioning.coordinate(nfLtevDisplay.vLAT,nfLtevDisplay.vLONG)
        }
    }
}
