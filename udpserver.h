#ifndef UDPSERVER_H
#define UDPSERVER_H

#include <QObject>
#include <QUdpSocket>
#include <QString>

class UdpServer : public QObject
{
    Q_OBJECT
public:
    explicit UdpServer(QObject *parent = 0);
    void sendDatagramm(QString myData, QHostAddress host, int port);
    void initSocket();

private:
    QUdpSocket *socket;

};

#endif // UDPSERVER_H

