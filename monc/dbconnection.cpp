#include "dbconnection.h"
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QVariant>
#include <string>
#include <CkHttpRequest.h>
#include <CkHttp.h>
#include <CkHttpResponse.h>

CkHttpRequest dbconnection::req;
CkHttp dbconnection::http;
CkHttpResponse dbconnection::resp = 0;

bool dbconnection::success;

dbconnection::http.put_AcceptCharset("");
dbconnection::http.put_UserAgent("");
dbconnection::http.put_AcceptLanguage("");
dbconnection::http.put_AllowGzip(false);

const char dbconnection::jsonText;

QSqlDatabase dbconnection::db;
QByteArray dbconnection::nuid;
QByteArray dbconnection::iban;
QByteArray dbconnection::transactie;

// https://www.example-code.com/cpp/http_post_json.asp
dbconnection::dbconnection()
{
//    db = QSqlDatabase::addDatabase("QMYSQL", "monc");
//    db.setHostName("127.0.0.1");
//    db.setDatabaseName("monc");
//    db.setUserName("root");
//    db.setPassword("root");
//    db.setPort(3306);//open poort op hogeschool server vinden
//    bool ok = db.open();
//    if(ok) {
//        qDebug("Db connection established");
//    }
//    else {
//        qDebug("Could not connect to db");
//    }
}

bool dbconnection::card(QByteArray data)
{
    nuid = data;
//    jsonText = "{iban="nuid,"&pin="pin"}";
//    resp = http.PostJson("https://monarchdouglasbank.tk/api/checkpin.php",jsonText);
//    QSqlQuery query(db);
//    query.exec("SELECT nuid FROM `card` WHERE nuid = '" + data + "';");
//    if(query.next())
//    {
//        nuid = query.value(0).toByteArray();
//        return true;
//    }
//    else
//    {
//        qWarning("No result");
//    }
    return true;
}

bool dbconnection::blocked()
{
    QSqlQuery query(db);
    query.exec("SELECT attempts FROM `card` WHERE nuid = '" + nuid + "';");
    if(query.next())
    {
        if(query.value(0).toInt()>=3)
        {
            return true;
        }
    }
    else
    {
        qWarning("No result");
    }
    return false;
}

bool dbconnection::getIban()
{
    QSqlQuery query(db);
    query.exec("SELECT iban FROM `cardaccount` WHERE nuid='"+nuid+"' LIMIT 1;");
    if(query.next())
    {
        iban = query.value(0).toByteArray();
        return true;
    }
    else
    {
        qWarning("No result");
    }
    return false;
}

int dbconnection::checkPin(QString pin)
{
    jsonText = "{iban="nuid,"&pin="pin"}";
    resp = http.PostJson("https://monarchdouglasbank.tk/api/checkpin.php",jsonText);
    QSqlQuery query(db);
    query.exec("SELECT nuid, pincode, attempts FROM `card` WHERE nuid='"+nuid+"';");
    if(query.next() && query.value(1).toString() == pin)
    {
        query.exec("UPDATE `card` SET `attempts`='0' WHERE `nuid`='"+nuid+"';");
        return 0;
    }
    else
    {
        int attempts = query.value(2).toInt();
        query.exec("UPDATE `card` SET `attempts`='"+QByteArray::number(attempts+1)+"' WHERE `nuid`='"+nuid+"';");
        return attempts+1;
    }
}

float dbconnection::getSaldo()
{
    QSqlQuery query(db);
    query.exec("SELECT balance FROM `account` WHERE iban='"+iban+"';");
    if(query.next())
    {
        return query.value(0).toFloat();
    }
    else
    {
        qWarning("No result");
    }
    return -9999.9;
}

bool dbconnection::withdraw(float amount)
{
    QSqlQuery query(db);
    float newAmount = getSaldo() - amount;
    if(newAmount >= 0){
        query.exec("INSERT INTO `transaction` (`iban`, `amount`, `atm_id`) VALUES ('"+ iban +"', '"+ QByteArray::number(amount*-1) +"', 'MONC');");
        query.exec("UPDATE `account` SET `balance`='"+QByteArray::number(newAmount)+"' WHERE `iban`='"+iban+"';");
        return true;
    }
    return false;
}

void dbconnection::log(QByteArray message)
{
    QSqlQuery query(db);
    query.exec("INSERT INTO `log` (`message`, `atm_id`) VALUES ('"+message+"', 'MONC');");
}

void dbconnection::stop()
{
    nuid = nullptr;
    transactie = nullptr;
    iban = nullptr;
}

void dbconnection::close()
{
    db.close();
    qWarning("Db connection closed");
}
