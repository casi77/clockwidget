#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QQuickView>
//#include "myudp.h"
#include "udpclient.h"
#include "udpserver.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_btn_ClientConnect_clicked();
    void on_btn_ServerStart_clicked();

    void on_DigitalChanger_actionTriggered(int action);
    void on_AnalogChanger_actionTriggered(int action);

public slots:
    void on_valueReceived(int value);
    void on_viewReceived(QString myView);

private:
    Ui::MainWindow *ui;
    UdpClient client;
    UdpServer server;
    QUrl digitalQML;
    QUrl analogueQML;
    QUrl emptyQML;
    QQuickView *view;
    QWidget *container;
};

#endif // MAINWINDOW_H
