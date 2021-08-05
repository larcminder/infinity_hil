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

    void on_skr_addline_button_clicked();

    void on_skr_removeLine_button_clicked();

    void on_skr_start_button_clicked();

    void on_pushButtonRefresh_clicked();

    void terminal(QString text);

    void on_dOutCh0_0_toggled(bool checked);

    void on_dOutCh0_1_toggled(bool checked);

    void on_dOutCh0_2_toggled(bool checked);

    void on_dOutCh0_3_toggled(bool checked);

    void on_dOutCh0_4_toggled(bool checked);

    void on_dOutCh0_5_toggled(bool checked);

    void on_dOutCh0_6_toggled(bool checked);

    void on_dOutCh0_7_toggled(bool checked);

    void on_dOutCh1_0_toggled(bool checked);

    void on_dOutCh1_1_toggled(bool checked);

    void on_dOutCh1_2_toggled(bool checked);

    void on_dOutCh1_3_toggled(bool checked);

    void on_dOutCh1_4_toggled(bool checked);

    void on_dOutCh1_5_toggled(bool checked);

    void on_dOutCh1_6_toggled(bool checked);

    void on_dOutCh1_7_toggled(bool checked);

signals:
    void new_command_available(QString command);

private:
    Ui::MainWindow *ui;
    QString rxMessage = "NULL";
    int ack = 0;
    int scriptStarted = 0;
    int scriptCurrentRow = 0;
    uint8_t digital_input_high_byte = 0;
    uint8_t digital_input_low_byte = 0;
    uint8_t digital_output_high_byte = 0;
    uint8_t digital_output_low_byte = 0;
};
#endif // MAINWINDOW_H
