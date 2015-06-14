import QtQuick 2.0

Image {
    id: root
    property double needleAngle : 0

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
        x: 100
        y: 67
        width: 200
        height: 200
        source: "needle.png"
        transform: Rotation{origin.x:164; origin.y:22; angle: needleAngle}
        smooth: true
    }

}

