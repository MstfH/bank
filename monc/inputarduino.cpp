#include "inputarduino.h"
#include "mainwindow.h"
#include <QDebug>
#include <QKeyEvent>
#include <QCoreApplication>
#include <string>

using namespace std;

InputArduino::InputArduino(MainWindow* _a)
{
    a = _a;
}

void InputArduino::input(QByteArray data)
{
    if(data.contains("RFID: "))
    {
        data.remove(0,6);
        data.trimmed();
        qDebug() << data;
        rfid(data);
    }
    else if(data.contains("KEY: "))
    {
        data.remove(0,5);
        data.trimmed();
        qDebug() << data;
        keys(data);
    }
}

void InputArduino::rfid(QByteArray data)
{
    if(a->getIndex() == 1) {
        a->on_buttonSkipDebug_pressed(data);
    }
}

void InputArduino::keys(QByteArray data)
{
    int pageIndex = a->getIndex();
    switch(pageIndex){
    case 0:
        a->on_buttonStart_pressed();
        break;
    case 1:
        pageScan(data);
        break;
    case 2:
        pagePincode(data);
        break;
    case 3:
        pageMenu(data);
        break;
    case 4:
        pageSaldo(data);
        break;
    case 5:
        pageOpnemen(data);
        break;
    case 6:
        pageBon(data);
        break;
    case 7:
        pageAnders(data);
        break;
    case 10:
        pageBiljet(data);
    default:
        break;
    }
}

void InputArduino::pageScan(QByteArray key)
{
    if(key == "#")
        a->on_buttonStop_pressed();
}

void InputArduino::pagePincode(QByteArray key)
{
    if(key == "#")
        a->on_buttonStop_pressed();
    else if(key == "0" || key == "1" || key == "2" || key == "3" || key == "4" || key == "5" || key == "6" || key == "7" || key == "8" || key == "9" || key == "A")
        a->insertPincode(key);
    else if(key == "D")
        a->on_buttonPinConfirm_pressed();
}

void InputArduino::pageMenu(QByteArray key)
{
    if(key == "#")
        a->on_buttonStop_pressed();
    else if(key == "A")
        a->on_buttonSaldo_pressed();
    else if(key == "B")
        a->on_buttonOpnemen_pressed();
    else if(key == "C")
        a->on_buttonSnel_pressed();
}

void InputArduino::pageSaldo(QByteArray key)
{
    if(key == "#")
        a->on_buttonStop_pressed();
    else if(key == "*")
        a->on_buttonBack_pressed();
}

void InputArduino::pageOpnemen(QByteArray key)
{
    if(key == "#")
        a->on_buttonStop_pressed();
    else if(key =="*")
        a->on_buttonBack_pressed();
    else if(key== "1")
        a->on_button20_pressed();
    else if(key == "2")
        a->on_button50_pressed();
    else if(key == "3")
        a->on_button100_pressed();
    else if(key == "4")
        a->on_button200_pressed();
    else if(key == "5")
        a->on_button500_pressed();
    else if(key == "6")
        a->on_buttonAnders_pressed();
}

void InputArduino::pageBon(QByteArray key)
{
    if(key =="A")
        a->on_buttonBonYes_pressed();
    else if(key =="D")
        a->on_buttonBonNo_pressed();
}

void InputArduino::pageAnders(QByteArray key)
{
    qDebug()<<"DONE";
    if(key == "#")
        a->on_buttonStop_pressed();
    else if(key == "0" || key == "1" || key == "2" || key == "3" || key == "4" || key == "5" || key == "6" || key == "7" || key == "8" || key == "9" || key == "A")
        a->insertAnderBedrag(key);
    else if(key == "D")
        a->on_buttonBedragConfirm_pressed();
    else if(key =="*")
        a->on_buttonBack_pressed();
}

void InputArduino::pageBiljet(QByteArray key)
{
    qDebug()<<"Do something";
    if(key == "1")
        a->on_buttonBiljet10_pressed();
    else if(key == "2")
        a->on_buttonBiljet20_pressed();
    else if(key == "3")
        a->on_buttonBiljet50_pressed();
    else if(key == "4")
        a->on_buttonMaaktNietUit_pressed();
    else if(key == "*")
        a->on_buttonBack_pressed();
    else if(key == "#")
        a->on_buttonStop_pressed();
}


