#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtSerialPort>
#include <QSerialPortInfo>
#include <QComboBox>
#include <QList>
#include <QString>
#include <QPlainTextEdit>
#include <QTextEdit>
#include <QObject>
#include <QTimer>

QSerialPort *serial;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    list_COM_devices();

    ui->aInCh1Text->insert(QString::number(0));
    ui->aOutCh1Text->insert(QString::number(0));

    ui->dInCh1->setDisabled(1);
    ui->dInCh1->setDisabled(1);

    serial = new QSerialPort(this);
}

MainWindow::~MainWindow()
{
    on_pushButtonDicsconnect_clicked();
    delete ui;
    serial->close();
}

/*** COM ***********************************************************************************/
void MainWindow::list_COM_devices() {
    QList<QSerialPortInfo> list;
    list = QSerialPortInfo::availablePorts();

    for(int i =0; i<list.length(); i++){
        ui->comboBoxPortSelect->addItem(list[i].portName());
    }
}

void MainWindow::on_pushButtonConnect_clicked()
{
    if(!(serial->isOpen())) {
        ui->rxText->append("Configuring Connection...");
        serial->setPortName(ui->comboBoxPortSelect->currentText());

        if(!serial->setBaudRate(QSerialPort::Baud9600))
            qDebug() << serial->errorString();
        if(!serial->setDataBits(QSerialPort::Data8))
            qDebug() << serial->errorString();
        if(!serial->setParity(QSerialPort::NoParity))
            qDebug() << serial->errorString();
        if(!serial->setFlowControl(QSerialPort::NoFlowControl))
            qDebug() << serial->errorString();
        if(!serial->setStopBits(QSerialPort::OneStop))
            qDebug() << serial->errorString();
        if(!serial->open(QIODevice::ReadWrite))
            qDebug() << serial->errorString();
        connect(serial,SIGNAL(readyRead()),this,SLOT(serialReceived()));
        if (serial->isOpen()) {
            ui->rxText->append("Sucessfully connected to COM Port");
        }else{
            ui->rxText->append("Failed to connect to COM Port");
        }

    }else{
        ui->rxText->append("Connection already open!");
    }

}

void MainWindow::transmit(QString msg) {
    ack = 0;
    ui->rxText->append("Tx: " + msg + "");
    msg.prepend('*');
    msg.append('#');
    qDebug() << "TX:" << msg;
    QByteArray inBytes;
    const char *cStrData;
    inBytes = msg.toUtf8();
    cStrData = inBytes.constData();
    QString qtStrData;
    qtStrData = QString::fromUtf8(cStrData);
    //qDebug() << qtStrData;
    serial->write(cStrData);
    serial->waitForBytesWritten();
}

void MainWindow::serialReceived() {

    QByteArray serialData = serial->readAll();
    QString tmp = QString::fromStdString(serialData.toStdString());
    //qDebug() << "recieved:" << tmp;
    if (tmp == "") {}
    else if (tmp.at(0) == '*') {
        rxMessage.clear();
        rxMessage.append(tmp);
    }
    else if (rxMessage.at(0) == '*') {
        rxMessage.append(tmp);

        if (rxMessage.contains('#') == true) {
            QStringList splitted = rxMessage.split('#');
            qDebug() << "List" << splitted;
            for (int i = 0; i < (splitted.length()-1); i++) {
                rxMessage = splitted[i];
                rxMessage.append('#');
                //qDebug() << "RX:" << rxMessage;
                analyzeCommand(rxMessage);
            }
            rxMessage = splitted[splitted.length()-1];

            if (rxMessage == "") {
                rxMessage = "NULL";
            }
        }
        /*
        if (splitted.length() > 1) {
            rxMessage = splitted[0];
            rxMessage.append('#');
            qDebug() << "RX:" << rxMessage;
            analyzeCommand(rxMessage);
            rxMessage = splitted[1];
            if (rxMessage == "") {
                rxMessage = "NULL";
            }
        }*/
    }
}

void MainWindow::analyzeCommand(QString command) {
    if (command.at(1) == 'p') {
        command.remove(0,2);
        command.chop(1);
        ui->rxText->append("Rx: " + command);
    }
    else if (command.at(1) == 'a') {
        ui->rxText->append("Nucleo confirmed!");
        if (scriptStarted == 1) {
            nextLine(scriptCurrentRow);
        }
    }
    else if (command.at(1) == 'd') {
        //set digital inputs
    }
}

/*** Script and other backgroud stuff **************************************/

void MainWindow::nextLine(int i) {
    auto item = ui->commandTable->item(i,0);
    if (!item) {
        scriptStarted = 0;
        terminal("Found empty cell, terminate script!");
        return;
    }
    QString cellText = item->text();
    transmit(cellText);
    if (i >= (ui->commandTable->rowCount() - 1)) {
        scriptStarted = 0;
        terminal("Script done!");
    }
    else {
        scriptCurrentRow++;
    }
}

void MainWindow::terminal(QString text) {
    ui->rxText->append(text);
}

/*** Buttons and UI ********************************************************/

void MainWindow::on_txButton_clicked()
{
    QString message = ui->txLine->text();
    transmit(message);
    ui->txLine->clear();
}

void MainWindow::on_txLine_returnPressed()
{
    MainWindow::on_txButton_clicked();
}

void MainWindow::on_pushButtonDicsconnect_clicked()
{
    if(serial->isOpen()){
        QByteArray serialData = serial->readAll();
        serialData.clear();
        serial->close(); //    Close the serial port if it's open.
        rxMessage = "NULL";
        ui->rxText->append("Closed connection");
    }else{
        ui->rxText->append("No open connection to be closed");
    }
}

void MainWindow::on_aOutCh1Slider_valueChanged(int value)
{
    int aOutCh1 = value;
    QString str = QString::number(aOutCh1);
    ui->aOutCh1Text->clear();
    ui->aOutCh1Text->insert(str);
    ui->aInCh1Text->clear();
    ui->aInCh1Text->insert(str);
    ui->aInCh1Progress->setValue(value);
}

void MainWindow::on_dOutCh1_toggled(bool checked)
{
    //int dOutCh1 = checked;
    ui->dInCh1->setEnabled(1);
    ui->dInCh1->setChecked(checked);
    ui->dInCh1->setDisabled(1);
}

void MainWindow::on_skr_addline_button_clicked()
{
    ui->commandTable->insertRow(ui->commandTable->rowCount());
}

void MainWindow::on_skr_removeLine_button_clicked()
{
    ui->commandTable->removeRow(ui->commandTable->rowCount() - 1);
}

void MainWindow::on_skr_start_button_clicked()
{
    scriptStarted = 1;
    scriptCurrentRow = 0;
    ui->rxText->append("Start running script...");
    nextLine(scriptCurrentRow);
}

void MainWindow::on_pushButtonRefresh_clicked()
{
    list_COM_devices();
}
