#include "udpclient.h"

//UdpClient Constructor
//in: *parent
//
//Constructs an object with parent object parent.
UdpClient::UdpClient(QObject *parent) :
    QObject(parent){
     qDebug() << "UDP Client Object created";
}

//initSocket
//in: qint64 port
//out: socketState
//
//inits the Client connection and binds to port. Returns the SocketState
 QAbstractSocket::SocketState UdpClient::initSocket(quint16 port){
    // create a QUDP socket
    socket = new QUdpSocket(this);

    // bind to a port
    socket->bind(port);

    //diagram arrives -> call readPendigDiagrams
    connect(socket, SIGNAL(readyRead()),
            this, SLOT(readPendingDatagrams()));
    //qDebug() << "Client Socket initialisiert: " << socket->state();

    return socket->state();
}

 //readPendingDiagrams
 //
 //when data arrives this function reads the pendig data and starts to decode it
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

//decodeInput
//in: QString input
//out: int
//
//decodes an String into an value. Dependig on Prefix its emits an Analogue signal
//or Digital signal and the corresponding value. Return the value from message
int UdpClient::decodeInput(QString input){
    int value = 0;

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
    qDebug() << "Decode Value: " << value;
    return value;
}

//disconnect
//out: Socketstate
//
//Disconnects from socket and return the SocketState
QAbstractSocket::SocketState UdpClient::disconnect(){
    socket->close();
    return socket->state();
}

//Destructor
UdpClient::~UdpClient(){
}

