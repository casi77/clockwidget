#include "udpserver.h"

UdpServer::UdpServer(QObject *parent) :
    QObject(parent){
     qDebug() << "UDP Server Object created";
}

QAbstractSocket::SocketState UdpServer::initSocket(){
    // create a QUDP socket
    socket = new QUdpSocket(this);

    qDebug() << "Server Socket initialisiert: ";

    return socket->state();
}

qint64 UdpServer::sendDatagramm(QString myData, QHostAddress host, int port){
    QByteArray data;
    qint64 returnValue;
    data.append(myData);

    // Sends the datagram datagram to the host address and at port.
    returnValue = socket->writeDatagram(data, host, port);
    //qDebug() << "Message send: " << data;

    return returnValue;
}
