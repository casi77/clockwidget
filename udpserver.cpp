#include "udpserver.h"

UdpServer::UdpServer(QObject *parent) :
    QObject(parent){
     qDebug() << "UDP Server Object created";
}

void UdpServer::initSocket(){
    // create a QUDP socket
    socket = new QUdpSocket(this);

    qDebug() << "Server Socket initialisiert: ";
}

void UdpServer::sendDatagramm(QString myData, QHostAddress host, int port){
    QByteArray data;
    data.append(myData);

    // Sends the datagram datagram to the host address and at port.
    socket->writeDatagram(data, host, port);
    //qDebug() << "Message send: " << data;
}
