import QtQuick 2.0
import QtLocation 5.6
import QtPositioning 5.6

Rectangle {
    id: window

    property double oldLat: 25.6585
    property double oldLng: 100.3658
    property Component markerComponent: mapMarker

    Plugin {
        id: mapPlugin
        name: "osm"
    }

    Map {
        id: mapView
        anchors.fill: parent
        plugin: mapPlugin
        center: QtPositioning.coordinate(oldLat, oldLng)
        zoomLevel: 6
    }

    function setCenter(lat, lng) {
        mapView.pan(oldLat - lat, oldLng - lng);
        oldLat = lat;
        oldLng = lng;
    }

    function addMarker(lat, lng) {
        var item = markerComponent.createObject(window, { coordinate: QtPositioning.coordinate(lat, lng) });
        mapView.addMapItem(item);
    }

    Connections {
        target: window

        // Connect the addMarker signal to the corresponding QML function
        onAddMarker: {
            addMarker(lat, lng);
            console.log("addMarker signal received successfully in QML");
        }
    }

    Component {
        id: mapMarker
        MapQuickItem {
            anchorPoint.x: image.width / 4
            anchorPoint.y: image.height
            coordinate: position

            sourceItem: Image {
                id: image
                source: "http://maps.gstatic.com/mapfiles/ridefinder-images/mm_20_red.png"
            }
        }
    }

    TextEdit {
        id: textEdit
        x: -357
        y: -96
        width: 80
        height: 20
        text: qsTr("Text Edit")
        font.pixelSize: 12
    }

    TextEdit {
        id: textEdit1
        x: -357
        y: -96
        width: 80
        height: 20
        text: qsTr("Text Edit")
        font.pixelSize: 12
    }
}
