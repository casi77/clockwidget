#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QQuickItem>



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
    emptyQML = QUrl("qrc:///empty/empty.qml");

    view->setSource(emptyQML);
    ui->verticalLayout->addWidget(container);
}

MainWindow::~MainWindow(){
    delete ui;
}

void MainWindow::on_btn_ClientConnect_clicked(){
    int clientPort = ui->client_inputPort->text().toInt();

    client.initSocket(clientPort);

    ui->client_inputPort->setEnabled(false);
    ui->btn_ClientConnect->setEnabled(false);


    connect(&client, SIGNAL(valueReceived(int)), this, SLOT(on_valueReceived(int)));
    connect(&client, SIGNAL(viewReceived(QString)), this, SLOT(on_viewReceived(QString)));
}

void MainWindow::on_btn_ServerStart_clicked(){

    server.initSocket();

    ui->serv_inputIP->setEnabled(false);
    ui->serv_inputPort->setEnabled(false);
    ui->AnalogChanger->setEnabled(true);
    ui->DigitalChanger->setEnabled(true);
}

void MainWindow::on_valueReceived(int value){

    qDebug() << "on Value Received";
    QQuickItem *item;
    item = view->rootObject();
    item->setProperty("value", value);
}

void MainWindow::on_viewReceived(QString myView) {

    QString anaString = "ANA";
    QString digString = "DIG";

    if (myView == anaString){
        view->setSource(analogueQML);
        ui->verticalLayout->addWidget(container);
    }
    else if(myView == digString){
        view->setSource(digitalQML);
        ui->verticalLayout->addWidget(container);
    }
    qDebug() << "View raises event: " << myView ;
}

void MainWindow::on_DigitalChanger_actionTriggered(int action){
    server.sendDatagramm("$DIG," + QString::number(ui->DigitalChanger->value()), QHostAddress(ui->serv_inputIP->text()), ui->serv_inputPort->text().toInt());
}

void MainWindow::on_AnalogChanger_actionTriggered(int action){
    server.sendDatagramm("$ANA," + QString::number(ui->AnalogChanger->value()), QHostAddress(ui->serv_inputIP->text()), ui->serv_inputPort->text().toInt());
}
