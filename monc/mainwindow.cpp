#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "serialread.h"
#include "dbconnection.h"
#include <QTime>
#include <QDebug>

QString MainWindow::pincode;
QString MainWindow::bedrag;
qint8 MainWindow::biljet10;
qint8 MainWindow::biljet20;
qint8 MainWindow::biljet50;

MainWindow::MainWindow(QWidget *parent) : QWidget(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(0);

    ui->buttonBack->setVisible(false);
    ui->buttonStop->setVisible(false);
    ui->buttonSkipDebug->setVisible(false);
    ui->buttonRestartDebug->setVisible(false);

    QWidget::showFullScreen();
}

MainWindow::~MainWindow()
{
    delete ui;
}

//MainWindow buttons
void MainWindow::on_buttonBack_pressed()
{
    switch(ui->stackedWidget->currentIndex())
    {
    case 4:
        ui->stackedWidget->setCurrentIndex(3);
        ui->buttonBack->setVisible(false);
        dbconnection::log("Returned to menu");
        break;
    case 5:
        ui->stackedWidget->setCurrentIndex(3);
        ui->buttonBack->setVisible(false);
        break;
    case 7:
        ui->stackedWidget->setCurrentIndex(5);
        dbconnection::log("Returned to withdraw");
        break;
    case 11:
        ui->stackedWidget->setCurrentIndex(5);
        dbconnection::log("Returned to withdraw");
        break;
    }
    ui->labelScanError->setText("");
    ui->labelPinError->setText("");
    ui->labelMenuError->setText("");
    ui->labelOpnemenError->setText("");
    ui->labelAndersError->setText("");
    ui->labelBiljetError->setText("");
    ui->labelErrorMessage->setText("");
    ui->txtBedrag->setText("");
    bedrag = "";
}

void MainWindow::on_buttonStop_pressed()
{
    dbconnection::log("Terminated session, back to start");
    ui->labelScanError->setText("");
    ui->labelPinError->setText("");
    ui->labelMenuError->setText("");
    ui->labelBiljetError->setText("");
    ui->labelOpnemenError->setText("");
    ui->labelAndersError->setText("");
    ui->labelErrorMessage->setText("");
    ui->stackedWidget->setCurrentIndex(0);
    ui->buttonBack->setVisible(false);
    ui->buttonStop->setVisible(false);
    pincode = "";
    dbconnection::nuid=nullptr;
    ui->pwPincode->setText("");
}

//Start screen buttons
void MainWindow::on_buttonStart_pressed()
{
    dbconnection::log("Start session, to card scan");
    ui->stackedWidget->setCurrentIndex(1);
    ui->buttonStop->setVisible(true);
}

//Pincode screen buttons
void MainWindow::on_buttonPinCorrection_pressed()
{}

void MainWindow::on_buttonPinConfirm_pressed()
{
    pincode = ui->pwPincode->text();

    int attempts = dbconnection::checkPin(pincode);
    if(attempts == 0)
    {
        if(dbconnection::getIban())
        {
            ui->labelPinError->setText("");
            ui->stackedWidget->setCurrentIndex(3);
            dbconnection::log("Succesful login, to menu");
        }
        else
        {
            ui->labelPinError->setText("Er is iets fout gegaan. Neem contact op met uw bank.");
        }
    }
    else
    {
        if(!dbconnection::blocked())
        {
            dbconnection::log("Not able to enter pin");
            ui->labelPinError->setText("Pincode onjuist. U heeft nog "+QByteArray::number(3-attempts)+" pogingen over");
        }
        else
        {
            dbconnection::log("Not able to enter pin, blocked card");
            ui->buttonStop->setVisible(false);
            ui->labelErrorMessage->setText("Pincode 3x onjuist ingevoerd. Uw pas is geblokkeerd.");
            ui->stackedWidget->setCurrentIndex(9);
            QTime dieTime= QTime::currentTime().addSecs(5);
            while (QTime::currentTime() < dieTime)
            {
                QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
            }
            on_buttonStop_pressed();
        }
    }
    pincode = "";
    ui->pwPincode->setText("");

}

//Menu screen buttons
void MainWindow::on_buttonSaldo_pressed()
{
    dbconnection::log("To balance screen");
    float saldo = dbconnection::getSaldo();
    ui->labelSaldo->setText(QLocale().toCurrencyString(saldo));
    ui->stackedWidget->setCurrentIndex(4);
    ui->buttonBack->setVisible(true);
}

void MainWindow::on_buttonOpnemen_pressed()
{
    dbconnection::log("To withdraw");
    ui->stackedWidget->setCurrentIndex(5);
    ui->buttonBack->setVisible(true);
}

void MainWindow::on_buttonSnel_pressed()
{
    if(dbconnection::withdraw(70))
    {
        dbconnection::log("Quick press €70 withdraw");
        ui->stackedWidget->setCurrentIndex(8);
        bedrag="70";
        ui->buttonBack->setVisible(false);
        ui->buttonStop->setVisible(false);
        QTime dieTime= QTime::currentTime().addSecs(5);
        while (QTime::currentTime() < dieTime)
        {
            QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
        }
        on_buttonStop_pressed();
    }
    else
    {
        dbconnection::log("Quick withdraw €70 fails");
        ui->labelMenuError->setText("Onvoldoende saldo");
    }
}

//Opnemen screen buttons
void MainWindow::on_button100_pressed()
{
    if(dbconnection::withdraw(100)){
        dbconnection::log("Withdraw €100");
        bedrag="100";
        ui->stackedWidget->setCurrentIndex(10);
    }
    else
    {
        dbconnection::log("Withdrawing €100 fails");
        ui->labelOpnemenError->setText("Onvoldoende saldo");
    }
}

void MainWindow::on_button20_pressed()
{
    if(dbconnection::withdraw(20)){
        dbconnection::log("Withdraw €20");
        bedrag="20";
        ui->stackedWidget->setCurrentIndex(10);
    }
    else
    {
        dbconnection::log("Withdrawing €20 fails");
        ui->labelOpnemenError->setText("Onvoldoende saldo");
    }
}

void MainWindow::on_button200_pressed()
{
    if(dbconnection::withdraw(200)){
        dbconnection::log("Withdraw €200");
        bedrag="200";
        ui->stackedWidget->setCurrentIndex(10);
    }
    else
    {
        dbconnection::log("Withdrawing €200 fails");
        ui->labelOpnemenError->setText("Onvoldoende saldo");
    }
}

void MainWindow::on_button50_pressed()
{
    if(dbconnection::withdraw(50)){
        dbconnection::log("Withdraw €50");
        bedrag="50";
        ui->stackedWidget->setCurrentIndex(10);
    }
    else
    {
        dbconnection::log("Withdrawing €50 fails");
        ui->labelOpnemenError->setText("Onvoldoende saldo");
    }
}

void MainWindow::on_button500_pressed()
{
    if(dbconnection::withdraw(500)){
        dbconnection::log("Withdraw €500");
        bedrag="500";
        ui->stackedWidget->setCurrentIndex(10);
    }
    else
    {
        dbconnection::log("Withdrawing €500 fails");
        ui->labelOpnemenError->setText("Onvoldoende saldo");
    }
}

void MainWindow::on_buttonAnders_pressed()
{
    dbconnection::log("To withdraw different amount");
    ui->stackedWidget->setCurrentIndex(7);
}

//Anders screen buttons
void MainWindow::on_buttonBedragCorrectie_pressed()
{}

void MainWindow::on_buttonBedragConfirm_pressed()
{
    bedrag = ui->txtBedrag->text();
    if(bedrag.toInt() % 10 == 0)
    {
        if(bedrag.toInt() > 9 && bedrag.toInt() < 501)
        {
            qDebug(QByteArray::number(bedrag.toFloat()));
            if(dbconnection::withdraw(bedrag.toFloat()))
            {
                dbconnection::log("Withdrew different amount");
                ui->stackedWidget->setCurrentIndex(10);
            }
            else
            {
                dbconnection::log("Withdraw different amount fails");
                ui->labelAndersError->setText("Onvoldoende saldo");
            }
        }
        else
        {
            ui->labelAndersError->setText("Bedrag moet tussen de 10 en 500 liggen");
        }
    }
    else
    {
        ui->labelAndersError->setText("Bedrag moet een veelvoud zijn van 10");
    }
    bedrag = "";
    ui->txtBedrag->setText("");
}

//Biljet screen buttons
void MainWindow::on_buttonBiljet10_pressed()
{
    dbconnection::log("Biljet of 10 wanted");
    biljet10 = bedrag.toInt()/10;
    qDebug()<<"Aantal biljetten van 10: "<<biljet10;
    ui->stackedWidget->setCurrentIndex(6);
    ui->buttonBack->setVisible(false);
    ui->buttonStop->setVisible(false);
}

void MainWindow::on_buttonBiljet20_pressed()
{
    dbconnection::log("Biljet of 20 wanted");
    if(bedrag.toInt() % 20 == 0)
    {
        biljet20 = bedrag.toInt()/20;
        qDebug()<<"Aantal biljetten van 20: "<<biljet20;
        ui->stackedWidget->setCurrentIndex(6);
        ui->buttonBack->setVisible(false);
        ui->buttonStop->setVisible(false);
    }
    else
    {
        biljet20=(bedrag.toInt()-(bedrag.toInt()%20))/20;
        biljet10=(bedrag.toInt()%20)/10;
        qDebug()<<"Aantal biljetten van 10: "<<biljet10;
        qDebug()<<"Aantal biljetten van 20: "<<biljet20;
        ui->stackedWidget->setCurrentIndex(6);
        ui->buttonBack->setVisible(false);
        ui->buttonStop->setVisible(false);
    }
}

void MainWindow::on_buttonBiljet50_pressed()
{
    dbconnection::log("Biljet of 50 wanted");
    if(bedrag.toInt()%50==0)
    {
        biljet50 = bedrag.toInt()/50;
        qDebug()<<"Aantal biljetten van 50: "<<biljet50;
        ui->stackedWidget->setCurrentIndex(6);
        ui->buttonBack->setVisible(false);
        ui->buttonStop->setVisible(false);
    }
    else if((bedrag.toInt()%50)%20==0)
    {
        biljet50=(bedrag.toInt()-(bedrag.toInt()%50))/50;
        biljet20=(bedrag.toInt()%50)/20;
        qDebug()<<"Aantal biljetten van 20: "<<biljet20;
        qDebug()<<"Aantal biljetten van 50: "<<biljet50;
        ui->stackedWidget->setCurrentIndex(6);
        ui->buttonBack->setVisible(false);
        ui->buttonStop->setVisible(false);
    }
    else
    {
        biljet50=(bedrag.toInt()-(bedrag.toInt()%50))/50;
        biljet20=(bedrag.toInt()%50-(bedrag.toInt()%50%20))/20;
        biljet10=(bedrag.toInt()%50%20)/10;
        qDebug()<<"Aantal biljetten van 10: "<<biljet10;
        qDebug()<<"Aantal biljetten van 20: "<<biljet20;
        qDebug()<<"Aantal biljetten van 50: "<<biljet50;
        ui->stackedWidget->setCurrentIndex(6);
        ui->buttonBack->setVisible(false);
        ui->buttonStop->setVisible(false);
    }
}

void MainWindow::on_buttonMaaktNietUit_pressed()
{
    dbconnection::log("Biljet does not matter");
    if(bedrag.toInt()%50==0)
    {
        biljet50 = bedrag.toInt()/50;
        qDebug()<<"Aantal biljetten van 50: "<<biljet50;
        ui->stackedWidget->setCurrentIndex(6);
        ui->buttonBack->setVisible(false);
        ui->buttonStop->setVisible(false);
    }
    else if((bedrag.toInt()%50)%20==0)
    {
        biljet50=(bedrag.toInt()-(bedrag.toInt()%50))/50;
        biljet20=(bedrag.toInt()%50)/20;
        qDebug()<<"Aantal biljetten van 20:"<<biljet20;
        qDebug()<<"Aantal biljetten van 50: "<<biljet50;
        ui->stackedWidget->setCurrentIndex(6);
        ui->buttonBack->setVisible(false);
        ui->buttonStop->setVisible(false);
    }
    else
    {
        biljet50=(bedrag.toInt()-(bedrag.toInt()%50))/50;
        biljet20=(bedrag.toInt()%50-(bedrag.toInt()%50%20))/20;
        biljet10=(bedrag.toInt()%50%20)/10;
        qDebug()<<"Aantal biljetten van 10: "<<biljet10;
        qDebug()<<"Aantal biljetten van 20: "<<biljet20;
        qDebug()<<"Aantal biljetten van 50: "<<biljet50;
        ui->stackedWidget->setCurrentIndex(6);
        ui->buttonBack->setVisible(false);
        ui->buttonStop->setVisible(false);
    }
}


//Bon screen buttons
void MainWindow::on_buttonBonYes_pressed()
{
    dbconnection::log("Reciept wanted");
    ui->stackedWidget->setCurrentIndex(8);
    QTime dieTime= QTime::currentTime().addSecs(5);
    while (QTime::currentTime() < dieTime)
    {
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
    }
    on_buttonStop_pressed();
}

void MainWindow::on_buttonBonNo_pressed()
{
    dbconnection::log("No reciept wanted");
    ui->stackedWidget->setCurrentIndex(8);
    QTime dieTime= QTime::currentTime().addSecs(5);
    while (QTime::currentTime() < dieTime)
    {
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
    }
    on_buttonStop_pressed();
}

//DEBUG BUTTONS
void MainWindow::on_buttonSkipDebug_pressed()
{ 
    if(dbconnection::card("505B8A7C"))
    {
        if(!dbconnection::blocked())
        {
            dbconnection::log("Card succesfully scanned, to menu");
            ui->labelScanError->setText("");
            ui->stackedWidget->setCurrentIndex(2);
        }
        else
        {
            dbconnection::log("Card scanning fails, card blocked");
            ui->labelScanError->setText("Kaart geblokkeerd. Neem contact op met uw bank.");
        }
    }
}

void MainWindow::on_buttonSkipDebug_pressed(QByteArray nuid)
{
    if(nuid!=nullptr)
    {
        if(dbconnection::card(nuid))
        {
            ui->stackedWidget->setCurrentIndex(2);

            //        if(!dbconnection::blocked())
            //        {
            //            dbconnection::log("Card succesfully scanned, to menu");
            //            ui->stackedWidget->setCurrentIndex(2);
            //        }
            //        else
            //        {
            //            dbconnection::log("Card scanning fails, card blocked");
            //            ui->labelScanError->setText("Kaart geblokkeerd. Neem contact op met uw bank");
            //        }
        }
    }
    else
    {
        ui->labelScanError->setText("Scan uw pas opnieuw.");
    }
}

void MainWindow::on_buttonRestartDebug_pressed()
{
    ui->stackedWidget->setCurrentIndex(0);
}

//Get current window
int MainWindow::getIndex()
{
    return ui->stackedWidget->currentIndex();
}

//Inserting stuff
void MainWindow::insertPincode(QByteArray key)
{
    if(key == "A")
    {
        if(pincode.length()>0)
        {
            pincode.remove(pincode.length() -1, 1);
        }
    }
    else
    {
        if(pincode.length()<5)
        {
            pincode.append(key);
        }
    }
    ui->pwPincode->setText(pincode);
}

void MainWindow::insertAnderBedrag(QByteArray key)
{
    if(key == "A")
    {
        if(bedrag.length()>0)
        {
            bedrag.remove(bedrag.length() -1, 1);
        }
    }
    else
    {
        if(bedrag.length()<3)
        {
            bedrag.append(key);
        }
    }
    ui->txtBedrag->setText(bedrag);
}

//Close window
void MainWindow::closeEvent(QCloseEvent *event)
{
    SerialRead::closePort();
    dbconnection::close();
    event->accept();
}
