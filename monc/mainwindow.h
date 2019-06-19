#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QCloseEvent>

namespace Ui {
class MainWindow;
}

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    int getIndex();

public slots:
    void on_buttonBack_pressed();
    void on_buttonStop_pressed();

    void on_buttonStart_pressed();

    void on_buttonPinCorrection_pressed();
    void on_buttonPinConfirm_pressed();

    void on_buttonSaldo_pressed();
    void on_buttonOpnemen_pressed();
    void on_buttonSnel_pressed();

    void on_button100_pressed();
    void on_button20_pressed();
    void on_button200_pressed();
    void on_button50_pressed();
    void on_button500_pressed();
    void on_buttonAnders_pressed();

    void on_buttonBedragCorrectie_pressed();
    void on_buttonBedragConfirm_pressed();

    void on_buttonBiljet10_pressed();
    void on_buttonBiljet20_pressed();
    void on_buttonBiljet50_pressed();
    void on_buttonMaaktNietUit_pressed();

    void on_buttonBonYes_pressed();
    void on_buttonBonNo_pressed();

    void on_buttonSkipDebug_pressed();
    void on_buttonSkipDebug_pressed(QByteArray nuid);
    void on_buttonRestartDebug_pressed();

    void insertPincode(QByteArray key);
    void insertAnderBedrag(QByteArray key);

    void closeEvent(QCloseEvent *event) override;

private:
    Ui::MainWindow *ui;
    static QString pincode;
    static QString bedrag;
    static qint8 biljet10;
    static qint8 biljet20;
    static qint8 biljet50;
};

#endif // MAINWINDOW_H
