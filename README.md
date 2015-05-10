# clockwidget
fh kiel, advanced c++ project

UDP Anwendung - kein TCP

Server schickt Nachrichten im Format: $[DIG/ANA],[WERT]
$DIG,56
oder
$ANA,56

1. Client Connect click
2. Server Start click
(Oder umgekehrt - egal!)

Danach können die Regler verschoben werden und der Server schickt Nachrichten an den Client

Todo 
- Nachricht Aufschlüsseln
    - Abhängig von ANA oder DIG Signal abschicken?
        - Neues Fenster mit Dynamischen QML öffnen

Vorsicht!!
- Keine Fehlerüberprüfung bei Eingaben!
- Nicht die Regler bewegen, wenn keine Verbindung aufgebaut ist :D
- Nix Errorhandling - yoyo! :P

Iwann grauen wir die Elemente aus, die man zu bestimmten Zeitpunkten nicht nutzen sollte. :)
