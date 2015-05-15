#ifndef MYUDP_H
#define MYUDP_H

#include <QObject>
#include <QUdpSocket>
#include <QString>

class MyUDP : public QObject
{
    Q_OBJECT
public:
    explicit MyUDP(QObject *parent = 0);
    void sendDatagramm(QString myData, QHostAddress host, int port);
    void initSocket(QHostAddress host, int port);
    void decodeInput(QString input);

signals:

public slots:
    void readyRead();

private:
    QUdpSocket *socket;

};

#endif // MYUDP_H
