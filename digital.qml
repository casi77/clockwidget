import QtQuick 2.0


    Rectangle
    {
        property string value: "0"
        x: 0
        y: 0
        width: 200
        height: 200

        Text {
            x: 58
            y: 80
            text: value
            font.pointSize: 26
            font.family: "Courier"
        }
    }
