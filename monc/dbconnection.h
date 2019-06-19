 #ifndef DBCONNECTION_H
#define DBCONNECTION_H

#include <QtSql/QSqlDatabase>
#include <QByteArray>
#include <CkHttpRequest.h>
#include <CkHttp.h>
#include <CkHttpResponse.h>

class dbconnection
{
private:
    static QSqlDatabase db;
    static QByteArray nuid;
    static QByteArray iban;
    static QByteArray transactie;
    const char *jsonText;
    CkHttpRequest req;
    CkHttp http;
    bool success;
    CkHttpResponse *resp;
public:
    dbconnection();
    static bool card(QByteArray nuid);
    static bool getIban();
    static int checkPin(QString pin);
    static bool blocked();
    static float getSaldo();
    static bool withdraw(float amount);
    static void log(QByteArray message);
    static void stop();
    static void close();
};

#endif // DBCONNECTION_H
