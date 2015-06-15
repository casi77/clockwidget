import QtQuick 2.0

    Rectangle
    {

        FontLoader {
            id: digital;
            source: "qrc:/fonts/digital-7.ttf" }

        property string value: "0000"
        property string oldValue: "0000"

        x: 0
        y: 0
        width: 400
        height: 185
        color: "#000000"
        border.width: 0
        border.color: "#000000"

        onValueChanged: {
            if(oldValue <= value) {
                textValue.color = "#31f311";
            }
            else {
                textValue.color = "red";

            }
            oldValue = value;
        }

        Text {
            id: textValue
            x: 56
            y: 34
            width: 288
            height: 136
            color: "#31f311"
            text: value
            font.family: digital.name
            horizontalAlignment: Text.AlignRight
            styleColor: "#000000"
            font.pointSize: 100
        }
    }
