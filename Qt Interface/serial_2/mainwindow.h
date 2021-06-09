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

    void transmit(QString msg);

    void analyzeCommand(QString command);

    void nextLine(int i);

    void list_COM_devices();

    void on_txLine_returnPressed();

    void on_pushButtonDicsconnect_clicked();

    void on_aOutCh1Slider_valueChanged(int value);

    void on_dOutCh1_toggled(bool checked);

    void on_skr_addline_button_clicked();

    void on_skr_removeLine_button_clicked();

    void on_skr_start_button_clicked();

    void on_pushButtonRefresh_clicked();

    void terminal(QString text);

signals:
    void new_command_available(QString command);

private:
    Ui::MainWindow *ui;
    QString rxMessage = "NULL";
    int ack = 0;
    int scriptStarted = 0;
    int scriptCurrentRow = 0;
};
#endif // MAINWINDOW_H
