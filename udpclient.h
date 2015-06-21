#ifndef UDPCLIENT
#define UDPCLIENT

#include <QObject>
#include <QUdpSocket>
#include <QString>

class UdpClient : public QObject
{
    Q_OBJECT
public:
    explicit UdpClient(QObject *parent = 0);
    QAbstractSocket::SocketState initSocket(quint16 port);
    int decodeInput(QString input);
    QAbstractSocket::SocketState disconnect();
    ~UdpClient();

signals:
    void valueReceived(int value);
    void viewReceived(QString myView);

public slots:
    void readPendingDatagrams();

private:
    QUdpSocket *socket;
    QString oldView;  //prevents view flicker
};

#endif // UDPCLIENT

