#include "serialread.h"
#include "mainwindow.h"
#include "inputarduino.h"
#include <QSerialPort>
#include <QDebug>
#include <QObject>
#include "QCloseEvent"

QSerialPort SerialRead::serialArduino;

SerialRead::SerialRead(InputArduino* _inputArduino)
{
    inputArduino = _inputArduino;
    qDebug() << "Serial begin";
    SerialRead::serialArduino.setPortName("/dev/ttyACM0");//Voor Windows goeie usb poort invullen COMX
    SerialRead::serialArduino.setBaudRate(QSerialPort::Baud9600);
    SerialRead::serialArduino.setDataBits(QSerialPort::Data8);
    SerialRead::serialArduino.setParity(QSerialPort::NoParity);
    SerialRead::serialArduino.setFlowControl(QSerialPort::NoFlowControl);
    SerialRead::serialArduino.setStopBits(QSerialPort::OneStop);
    SerialRead::serialArduino.open(QIODevice::ReadOnly);
}

void SerialRead::serialReceived()
{
    QObject::connect(&SerialRead::serialArduino, &QSerialPort::readyRead, [&]
    {
        //readyRead() is emitted
        QByteArray datas = SerialRead::serialArduino.readAll();
        //qDebug() << datas;
        charBuffer.append(datas);
        if(datas.contains("\n"))
        {
            charBuffer = charBuffer.trimmed();
            //qDebug() << charBuffer;
            inputArduino->input(charBuffer);
            charBuffer.clear();
        }
    });

    QObject::connect(&SerialRead::serialArduino,
                     static_cast<void(QSerialPort::*)(QSerialPort::SerialPortError)>
                     (&QSerialPort::error),
                     [&](QSerialPort::SerialPortError error)
    {
        //serial communication error
        qDebug() << "An error occured: " << error;
        return;
    });
}

void SerialRead::closePort()
{
    SerialRead::serialArduino.close();
    qWarning("Serial communication has stopped");
}
