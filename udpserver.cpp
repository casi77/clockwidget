#include "udpserver.h"

//UdpServer Constructor
//in: *parent
//
//Constructs an object with parent object parent.
UdpServer::UdpServer(QObject *parent) :
    QObject(parent){
     qDebug() << "UDP Server Object created";
}

//initSocket
//in: qint64 port
//out: socketState
//
//inits the Server connection. Returns the SocketState
QAbstractSocket::SocketState UdpServer::initSocket(){
    // create a QUDP socket
    socket = new QUdpSocket(this);

    qDebug() << "Server Socket initialisiert: ";

    return socket->state();
}

//sendDatagram
//in: QString myData
//    QHostAdress host
//    int port
//out: qint64
//
//Sends the datagram at data of size size to the host address address at port port.
//Returns the number of bytes sent on success; otherwise returns -1.
qint64 UdpServer::sendDatagramm(QString myData, QHostAddress host, int port){
    QByteArray data;
    qint64 returnValue;
    data.append(myData);

    // Sends the datagram datagram to the host address and at port.
    returnValue = socket->writeDatagram(data, host, port);
    //qDebug() << "Message send: " << data;

    return returnValue;
}

//Destructor
UdpServer::~UdpServer(){
}
