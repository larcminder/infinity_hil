/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QComboBox *comboBoxPortSelect;
    QPushButton *pushButtonConnect;
    QLabel *label_2;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QTextBrowser *rxText;
    QWidget *layoutWidget_2;
    QHBoxLayout *horizontalLayout;
    QLineEdit *txLine;
    QPushButton *txButton;
    QPushButton *pushButtonDicsconnect;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(884, 662);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        comboBoxPortSelect = new QComboBox(centralwidget);
        comboBoxPortSelect->setObjectName(QString::fromUtf8("comboBoxPortSelect"));
        comboBoxPortSelect->setGeometry(QRect(10, 50, 141, 22));
        pushButtonConnect = new QPushButton(centralwidget);
        pushButtonConnect->setObjectName(QString::fromUtf8("pushButtonConnect"));
        pushButtonConnect->setGeometry(QRect(160, 50, 75, 23));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 30, 91, 16));
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(370, 10, 258, 551));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout->addWidget(label);

        rxText = new QTextBrowser(layoutWidget);
        rxText->setObjectName(QString::fromUtf8("rxText"));

        verticalLayout->addWidget(rxText);

        layoutWidget_2 = new QWidget(centralwidget);
        layoutWidget_2->setObjectName(QString::fromUtf8("layoutWidget_2"));
        layoutWidget_2->setGeometry(QRect(10, 90, 341, 25));
        horizontalLayout = new QHBoxLayout(layoutWidget_2);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        txLine = new QLineEdit(layoutWidget_2);
        txLine->setObjectName(QString::fromUtf8("txLine"));

        horizontalLayout->addWidget(txLine);

        txButton = new QPushButton(layoutWidget_2);
        txButton->setObjectName(QString::fromUtf8("txButton"));

        horizontalLayout->addWidget(txButton);

        pushButtonDicsconnect = new QPushButton(centralwidget);
        pushButtonDicsconnect->setObjectName(QString::fromUtf8("pushButtonDicsconnect"));
        pushButtonDicsconnect->setGeometry(QRect(240, 50, 75, 23));
        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        pushButtonConnect->setText(QCoreApplication::translate("MainWindow", "Connect", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Select COM Port", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Received:", nullptr));
        txButton->setText(QCoreApplication::translate("MainWindow", "Transmit", nullptr));
        pushButtonDicsconnect->setText(QCoreApplication::translate("MainWindow", "Disconnect", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
