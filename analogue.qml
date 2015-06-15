import QtQuick 2.0

Image {
    id: root
    property double value : 0
    property double oldValue : 0
    width: 400
    height: 185
    Image {
        id: background
        x:0
        y:0
        width: 400
        height: 300
        fillMode: Image.Tile
        sourceSize.height: 300
        sourceSize.width: 400
        source: "background.png"
    }

    onValueChanged: {
        if(oldValue <= value) {
            textValue.color = "#31f311";
        }
        else {
            textValue.color = "red";

        }
        oldValue = value;
    }

    Image {
        id: needle
        x: 0
        y: 0
        width: 400
        height: 300
        sourceSize.height: 300
        sourceSize.width: 400
        fillMode: Image.Tile
        rotation: value * 1.8;
        //clip: false
        source: "needle.png"
        smooth: true
    }


    Text {
        id: textValue
        x: 0
        y: 0
        text: value
        font.family: courir
        horizontalAlignment: Text.AlignRight
        styleColor: "#000000"
        font.pointSize: 12
    }

}

