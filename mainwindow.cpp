#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btn_ClientConnect_clicked()
{
    int clientPort = ui->client_inputPort->text().toInt();
    QString clientIP = ui->client_inputIP->text();

    client.initSocket(QHostAddress(clientIP), clientPort);
}

void MainWindow::on_btn_ServerStart_clicked()
{
    int serverPort = ui->serv_inputPort->text().toInt();
    QString serverIP = ui->serv_inputIP->text();

    server.initSocket(QHostAddress(serverIP), serverPort);
    //server.sendDatagramm("TESTTEST", QHostAddress(serverIP), serverPort);
}

void MainWindow::on_DigitalChanger_actionTriggered(int action)
{
    server.sendDatagramm("$DIG," + QString::number(ui->DigitalChanger->value()), QHostAddress(ui->serv_inputIP->text()), ui->serv_inputPort->text().toInt());
}

void MainWindow::on_AnalogChanger_actionTriggered(int action)
{
    server.sendDatagramm("$ANA," + QString::number(ui->AnalogChanger->value()), QHostAddress(ui->serv_inputIP->text()), ui->serv_inputPort->text().toInt());
}
