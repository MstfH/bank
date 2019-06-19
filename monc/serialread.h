#ifndef SERIALREAD_H
#define SERIALREAD_H

#include <QSerialPort>
#include "mainwindow.h"
#include "inputarduino.h"

class SerialRead
{
public:
    SerialRead(InputArduino* _inputArduino);
    static QSerialPort serialArduino;
    void serialReceived ();
    static void closePort();

private:
    InputArduino* inputArduino;
    QByteArray charBuffer;
};

#endif // SERIALREAD_H
