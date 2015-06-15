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
    void initSocket(quint16 port);
    void decodeInput(QString input);

signals:
    void valueReceived(int value);
    void viewReceived(QString myView);

public slots:
    void readPendingDatagrams();

private:
    QUdpSocket *socket;
    QString oldView;
};

#endif // UDPCLIENT

