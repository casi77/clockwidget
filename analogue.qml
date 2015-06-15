import QtQuick 2.0

Image {
    id: root
    property double value : 0
    //width: 210; height: 210 //why?!

    Image {
        id: background
        x:0
        y:0
        width: 440
        height: 300
        source: "background.png"
    }

    Image {
        id: needle
        x: 128
        y: 100
        width: 184
        height: 200
        rotation: value;
        //clip: false
        source: "needle.png"
        smooth: true
    }

}

