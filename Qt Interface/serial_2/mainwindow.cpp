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

QSerialPort *serial;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    serialBuffer = "";
    //QString currentConnection = "";
    QList<QSerialPortInfo> list;
    list = QSerialPortInfo::availablePorts();

    for(int i =0; i<list.length(); i++){
        ui->comboBoxPortSelect->addItem(list[i].portName());
    }

    serial = new QSerialPort(this);
}

MainWindow::~MainWindow()
{
    delete ui;
    serial->close();
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

void MainWindow::on_txButton_clicked()
{
    QString msg = ui->txLine->text();
    QByteArray inBytes;
    const char *cStrData;
    inBytes = msg.toUtf8();
    cStrData = inBytes.constData();
    QString qtStrData;
    qtStrData = QString::fromUtf8(cStrData);
    serial->write(cStrData);
    ui->rxText->append("Sent: " + msg + "");
    ui->txLine->clear();

}

void MainWindow::serialReceived() {

    serialData = serial->readAll();
    serialBuffer = serialBuffer + QString::fromStdString(serialData.toStdString());
    serialData.clear();
    qDebug() << "Buffer: " << serialBuffer;

    if (serialBuffer.length() >= 4){
        ui->rxText->append("Received: " + serialBuffer + "");
        serialBuffer.remove(0,4);
    }
}

void MainWindow::on_txLine_returnPressed()
{
    MainWindow::on_txButton_clicked();
}

void MainWindow::on_pushButtonDicsconnect_clicked()
{
    if(serial->isOpen()){
        serial->close(); //    Close the serial port if it's open.
        serialBuffer = "";
        serialData = "";
        ui->rxText->append("Closed connection");
    }else{
        ui->rxText->append("No open connection to be closed");
    }
}

