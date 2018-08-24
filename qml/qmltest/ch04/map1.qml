import QtQuick 2.0
import QtLocation 5.6
import QtPositioning 5.6

Item {
    id: bg
    width: 1024; height: 600

    property double latitude : 39.9068727588
    property double longitude: 119.5314224308

    Plugin{
        id: mapboxPlugin
        name: "mapbox"
        PluginParameter{
            name: "mapbox.mapping.highdpi_tiles"
            value: true
        }
        PluginParameter{
            name: "mapbox.access_token";
            value: "pk.****************************************************"
        }
    }
    Rectangle{
        id: mapArea
        width: parent.width; height: parent.height
        anchors{
            horizontalCenter: parent.horizontalCenter
            verticalCenter: parent.verticalCenter
        }
        color: "black"
        Map{
            id: map
            width: parent.width; height: parent.height
            anchors.centerIn: parent
            scale: 2
            plugin: mapboxPlugin
            center: QtPositioning.coordinate(latitude, longitude)
            zoomLevel: 16
            activeMapType: supportedMapTypes[3]
            MapQuickItem{
                id: marker
                anchorPoint.x: image.width/2
                anchorPoint.y: image.height/2
                transformOrigin: Item.Center
                scale: 0.5
                rotation: 0
                sourceItem: Image {
                    id: image
                    source: "assets/navigation.png"
                }
                coordinate:QtPositioning.coordinate(latitude, longitude)
            }
        }
    }
}
