#include "mainwindow.h"
#include "serialread.h"
#include <dbconnection.h>
#include <QDebug>
#include <QtCore/QCoreApplication>
#include <QApplication>
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    dbconnection db;

    InputArduino r(&w);
    SerialRead s(&r);

    w.show();
    s.serialReceived();

    return a.exec();
}
