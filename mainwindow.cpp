#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->DigitalChanger->setEnabled(false);
    ui->AnalogChanger->setEnabled(false);

    view = new QQuickView();
    container = QWidget::createWindowContainer(view, this);

    //Because qrc:// is the URL prefix, / is the root prefix, digital.qml is the file inside it.
    digitalQML = QUrl("qrc:///digital/digital.qml");

    analogueQML = QUrl("qrc:///analogue/analogue.qml");

    view->setSource(analogueQML);
    ui->verticalLayout->addWidget(container);
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

    ui->client_inputIP->setEnabled(false);
    ui->client_inputPort->setEnabled(false);
}

void MainWindow::on_btn_ServerStart_clicked()
{
    int serverPort = ui->serv_inputPort->text().toInt();
    QString serverIP = ui->serv_inputIP->text();

    server.initSocket(QHostAddress(serverIP), serverPort);
    //server.sendDatagramm("TESTTEST", QHostAddress(serverIP), serverPort);

    ui->serv_inputIP->setEnabled(false);
    ui->serv_inputPort->setEnabled(false);

    ui->AnalogChanger->setEnabled(true);
    ui->DigitalChanger->setEnabled(true);

        //view->setSource(digitalQML);
        //ui->verticalLayout->addWidget(container);
        view->setProperty("value", "hallo");
        qDebug() << view->property("value");

        view->update();

        container->repaint();
}

void MainWindow::on_DigitalChanger_actionTriggered(int action)
{
    server.sendDatagramm("$DIG," + QString::number(ui->DigitalChanger->value()), QHostAddress(ui->serv_inputIP->text()), ui->serv_inputPort->text().toInt());
}

void MainWindow::on_AnalogChanger_actionTriggered(int action)
{
    server.sendDatagramm("$ANA," + QString::number(ui->AnalogChanger->value()), QHostAddress(ui->serv_inputIP->text()), ui->serv_inputPort->text().toInt());
    ui->verticalLayout->setProperty("needleAngle", ui->AnalogChanger->value());
}
