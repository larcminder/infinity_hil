#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButtonConnect_clicked();

    void on_txButton_clicked();

    void serialReceived();

    void on_txLine_returnPressed();

    void on_pushButtonDicsconnect_clicked();

private:
    Ui::MainWindow *ui;
    QByteArray serialData;
    QString serialBuffer;
};
#endif // MAINWINDOW_H
