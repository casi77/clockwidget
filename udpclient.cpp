#include "udpclient.h"

UdpClient::UdpClient(QObject *parent) :
    QObject(parent){
     qDebug() << "UDP Client Object created";
}

void UdpClient::initSocket(quint16 port){
    // create a QUDP socket
    socket = new QUdpSocket(this);

    // bind to a port
    socket->bind(port);

    connect(socket, SIGNAL(readyRead()),
            this, SLOT(readPendingDatagrams()));
    qDebug() << "Client Socket initialisiert: " << socket->state();
}

void UdpClient::readPendingDatagrams(){

    while (socket->hasPendingDatagrams()) {

        QByteArray datagram;
        datagram.resize(socket->pendingDatagramSize());
        QHostAddress sender;
        quint16 senderPort;

        socket->readDatagram(datagram.data(), datagram.size(),
                             &sender, &senderPort);

        //qDebug() << "Data received: " << datagram;
        decodeInput(datagram);
    }
}

void UdpClient::decodeInput(QString input){
    int value;

    //qDebug() << "Decode Input";

    QString anaString = "ANA";
    QString digString = "DIG";

    //qDebug() << input;
    //qDebug() << input.indexOf(anaString);

    if (input.indexOf(digString) != -1){
        value = input.mid(5, input.length()-1).toInt();
        //qDebug() << "Decoded: " << "DIG" << " & " << "value: " << value;

        //Entfernt das Flackern
        if (oldView != digString){
            emit viewReceived(digString);
            oldView = digString;
        }

        emit valueReceived(value);
    }
    if (input.indexOf(anaString) != -1){
        value = input.mid(5, input.length()-1).toInt();
        //qDebug() << "Decoded: " << "ANA" << " & " << "value: " << value;

        //Entfernt das Flackern
        if (oldView != anaString){
            emit viewReceived(anaString);
            oldView = anaString;
        }

        emit valueReceived(value);
    }
}

