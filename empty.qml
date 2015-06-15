import QtQuick 2.0


    Rectangle
    {
        property string value: ""
        x: 0
        y: 0
        width: 300
        height: 185

        Text {
            x: 20
            y: 79
            text: "No value received!"
            font.pointSize: 18
            font.family: "Courier"
        }
    }
