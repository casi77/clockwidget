#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "myudp.h"

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

private:
    Ui::MainWindow *ui;
    MyUDP client;
    MyUDP server;
};

#endif // MAINWINDOW_H
