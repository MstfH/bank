#ifndef INPUTARDUINO_H
#define INPUTARDUINO_H

#include "mainwindow.h"
#include <QByteArray>

class InputArduino
{
public:
    InputArduino(MainWindow* _a);
    void input(QByteArray);
private:
    MainWindow* a;
    void keys(QByteArray);
    void rfid(QByteArray);

    void pageScan(QByteArray);
    void pagePincode(QByteArray);
    void pageMenu(QByteArray);
    void pageSaldo(QByteArray);
    void pageOpnemen(QByteArray);
    void pageBon(QByteArray);
    void pageAnders(QByteArray);
    void pageBiljet(QByteArray);
};

#endif // INPUTARDUINO_H
