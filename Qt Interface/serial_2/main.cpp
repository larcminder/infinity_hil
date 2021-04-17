#include "mainwindow.h"

#include <QApplication>
#include <QtSerialPort>
#include <QSerialPortInfo>
#include <QComboBox>
#include <QList>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setWindowTitle("Serial Interface");
    w.show();
    return a.exec();
}
