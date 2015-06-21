#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QQuickItem>


//Constructor
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->DigitalChanger->setEnabled(false);
    ui->AnalogChanger->setEnabled(false);
    ui->btn_ClientDisconnect->setEnabled(false);
    ui->btn_ServerEnd->setEnabled(false);

    view = new QQuickView();
    container = QWidget::createWindowContainer(view, this);

    //Because qrc:// is the URL prefix, / is the root prefix, digital.qml is the file inside it.
    digitalQML = QUrl("qrc:///digital/digital.qml");
    analogueQML = QUrl("qrc:///analogue/analogue.qml");
    emptyQML = QUrl("qrc:///empty/empty.qml");

    view->setSource(emptyQML);
    ui->verticalLayout->addWidget(container);
}

//Destructor Main
MainWindow::~MainWindow(){
    delete ui;
}

//Client - Connect clocked
//changes view elements to active/deactive, inits the Client and connects signals and slots
void MainWindow::on_btn_ClientConnect_clicked(){
    int clientPort = ui->client_inputPort->text().toInt();

    client.initSocket(clientPort);

    ui->client_inputPort->setEnabled(false);
    ui->btn_ClientConnect->setEnabled(false);
    ui->btn_ClientDisconnect->setEnabled(true);

    //connect client signals with window slots
    connect(&client, SIGNAL(valueReceived(int)), this, SLOT(on_valueReceived(int)));
    connect(&client, SIGNAL(viewReceived(QString)), this, SLOT(on_viewReceived(QString)));
}

//Server - Start clicked
//changes view elements to active/deactive and inits the Server
void MainWindow::on_btn_ServerStart_clicked(){

    server.initSocket();

    ui->serv_inputIP->setEnabled(false);
    ui->serv_inputPort->setEnabled(false);
    ui->AnalogChanger->setEnabled(true);
    ui->DigitalChanger->setEnabled(true);
    ui->btn_ServerEnd->setEnabled(true);
    ui->btn_ServerStart->setEnabled(false);
}

//on Signal value received
//sets on QML view the value
void MainWindow::on_valueReceived(int value){

    qDebug() << "on Value Received";
    QQuickItem *item;
    item = view->rootObject();
    item->setProperty("value", value);
}

//on Signal view received
//Changes the view, depending on ANA for analogue and DIG for digital
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

//Server - Digital slider changes
//Sends the digital slider value to destination
void MainWindow::on_DigitalChanger_actionTriggered(int action){
    server.sendDatagramm("$DIG," + QString::number(ui->DigitalChanger->value()), QHostAddress(ui->serv_inputIP->text()), ui->serv_inputPort->text().toInt());
}

//Server - Analogue slider changes
//Sends the analogue slider value to destination
void MainWindow::on_AnalogChanger_actionTriggered(int action){
    server.sendDatagramm("$ANA," + QString::number(ui->AnalogChanger->value()), QHostAddress(ui->serv_inputIP->text()), ui->serv_inputPort->text().toInt());
}

//Client - Disconnect clicked
//Diconnects the client, changes view element visibility and deletes the client
void MainWindow::on_btn_ClientDisconnect_clicked()
{
   client.disconnect();

   ui->client_inputPort->setEnabled(true);
   ui->btn_ClientConnect->setEnabled(true);
   ui->btn_ClientDisconnect->setEnabled(false);
   delete client.parent();
}

//Server - End clicked
//Changes view element visibility and deletes the server
void MainWindow::on_btn_ServerEnd_clicked()
{
    ui->serv_inputIP->setEnabled(true);
    ui->serv_inputPort->setEnabled(true);
    ui->DigitalChanger->setEnabled(false);
    ui->AnalogChanger->setEnabled(false);
    ui->btn_ServerEnd->setEnabled(false);
    ui->btn_ServerStart->setEnabled(true);
    delete server.parent();
}
