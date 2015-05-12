#include "myudp.h"

MyUDP::MyUDP(QObject *parent) :
    QObject(parent)
{
     qDebug() << "UDP Object";
}

void MyUDP::initSocket(QHostAddress host, int port)
{
    // create a QUDP socket
    socket = new QUdpSocket(this);

    // bind to an address and port
    socket->bind(host, port);

    connect(socket, SIGNAL(readyRead()), this, SLOT(readyRead()));
    qDebug() << "Socket init rdy";
}

void MyUDP::sendDatagramm(QString myData, QHostAddress host, int port)
{
    QByteArray data;
    data.append(myData);

    // Sends the datagram datagram to the host address and at port.
    socket->writeDatagram(data, host, port);

    qDebug() << "Message send: " << data;
}

void MyUDP::readyRead()
{
    // when data comes in
    QByteArray buffer;
    buffer.resize(socket->pendingDatagramSize());

    QHostAddress sender;
    quint16 senderPort;

    // qint64 QUdpSocket::readDatagram(char * data, qint64 maxSize,
    //                 QHostAddress * address = 0, quint16 * port = 0)
    // Receives a datagram no larger than maxSize bytes and stores it in data.
    // The sender's host address and port is stored in *address and *port
    // (unless the pointers are 0).

    socket->readDatagram(buffer.data(), buffer.size(),
                         &sender, &senderPort);

    //qDebug() << "Message from: " << sender.toString();
    //qDebug() << "Message port: " << senderPort;
    //qDebug() << "Message: " << buffer;

    qDebug() << "Message recived: " << buffer;

    decodeInput(buffer);
}

void MyUDP::decodeInput(QString input)
{
    qDebug() << "Decode Input";

    QString anaString = "ANA";
    QString digString = "DIG";

    qDebug() << input;
    qDebug() << input.indexOf(anaString);

    if (input.indexOf(anaString) != -1)
    {
        qDebug() <<  "ANA FOUND ";
    }
    if (input.indexOf(digString) != -1)
    {
        qDebug() <<  "DIG FOUND ";
    }
}
