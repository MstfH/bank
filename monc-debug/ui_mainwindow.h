/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QStackedWidget *stackedWidget;
    QWidget *start;
    QPushButton *buttonStart;
    QLabel *moto;
    QWidget *pasScan;
    QLabel *labelScan;
    QLabel *imgScan;
    QLabel *labelScanError;
    QPushButton *buttonSkipDebug;
    QWidget *pincodeInvoeren;
    QLineEdit *pwPincode;
    QPushButton *buttonPinCorrection;
    QPushButton *buttonPinConfirm;
    QLabel *labelPinError;
    QWidget *menu;
    QPushButton *buttonSaldo;
    QPushButton *buttonOpnemen;
    QPushButton *buttonSnel;
    QLabel *labelMenuError;
    QWidget *saldo;
    QLabel *labelSaldoText;
    QLabel *labelSaldo;
    QWidget *opnemen;
    QPushButton *button20;
    QPushButton *button100;
    QPushButton *button500;
    QPushButton *buttonAnders;
    QLabel *labelOpnemenError;
    QPushButton *button50;
    QPushButton *button200;
    QWidget *bonKeuze;
    QLabel *labelBon;
    QLabel *imgBon;
    QPushButton *buttonBonYes;
    QPushButton *buttonBonNo;
    QWidget *anderBedrag;
    QLineEdit *txtBedrag;
    QLabel *labelDescription;
    QLabel *labelAndersError;
    QPushButton *buttonBedragCorrectie;
    QPushButton *buttonBedragConfirm;
    QWidget *uitgifte;
    QLabel *labelOnthoudGeld;
    QLabel *labelTotziens;
    QLabel *imgUitgifte;
    QPushButton *buttonRestartDebug;
    QWidget *Error;
    QLabel *labelErrorMessage;
    QLabel *labelTitle;
    QPushButton *buttonStop;
    QPushButton *buttonBack;
    QLabel *saatbank;
    QLabel *saattext;

    void setupUi(QWidget *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1920, 1080);
        QFont font;
        font.setFamily(QStringLiteral("Arial"));
        MainWindow->setFont(font);
        MainWindow->setAutoFillBackground(false);
        MainWindow->setStyleSheet(QStringLiteral("background-color: rgb(0, 0, 0);"));
        stackedWidget = new QStackedWidget(MainWindow);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        stackedWidget->setGeometry(QRect(0, 200, 1920, 780));
        stackedWidget->setStyleSheet(QStringLiteral("background-color: rgb(106, 149, 123);"));
        start = new QWidget();
        start->setObjectName(QStringLiteral("start"));
        start->setEnabled(true);
        start->setFont(font);
        buttonStart = new QPushButton(start);
        buttonStart->setObjectName(QStringLiteral("buttonStart"));
        buttonStart->setGeometry(QRect(335, 505, 1250, 245));
        QFont font1;
        font1.setFamily(QStringLiteral("Arial"));
        font1.setPointSize(48);
        buttonStart->setFont(font1);
        moto = new QLabel(start);
        moto->setObjectName(QStringLiteral("moto"));
        moto->setGeometry(QRect(617, 30, 595, 415));
        moto->setPixmap(QPixmap(QString::fromUtf8(":/Images/Resources/Images/gimmeyourmoney.png")));
        moto->setScaledContents(true);
        moto->setAlignment(Qt::AlignCenter);
        stackedWidget->addWidget(start);
        pasScan = new QWidget();
        pasScan->setObjectName(QStringLiteral("pasScan"));
        pasScan->setFont(font);
        labelScan = new QLabel(pasScan);
        labelScan->setObjectName(QStringLiteral("labelScan"));
        labelScan->setGeometry(QRect(710, 350, 531, 291));
        QFont font2;
        font2.setFamily(QStringLiteral("Arial"));
        font2.setPointSize(10);
        labelScan->setFont(font2);
        labelScan->setPixmap(QPixmap(QString::fromUtf8(":/Images/Resources/Images/rfid-logo.png")));
        labelScan->setScaledContents(true);
        labelScan->setAlignment(Qt::AlignCenter);
        imgScan = new QLabel(pasScan);
        imgScan->setObjectName(QStringLiteral("imgScan"));
        imgScan->setGeometry(QRect(0, 175, 1920, 71));
        QFont font3;
        font3.setFamily(QStringLiteral("Arial"));
        font3.setPointSize(36);
        imgScan->setFont(font3);
        imgScan->setAlignment(Qt::AlignCenter);
        labelScanError = new QLabel(pasScan);
        labelScanError->setObjectName(QStringLiteral("labelScanError"));
        labelScanError->setGeometry(QRect(0, 40, 1920, 81));
        QFont font4;
        font4.setFamily(QStringLiteral("Arial"));
        font4.setPointSize(30);
        font4.setBold(true);
        font4.setWeight(75);
        labelScanError->setFont(font4);
        labelScanError->setStyleSheet(QStringLiteral("color: rgb(164, 0, 0);"));
        labelScanError->setAlignment(Qt::AlignCenter);
        buttonSkipDebug = new QPushButton(pasScan);
        buttonSkipDebug->setObjectName(QStringLiteral("buttonSkipDebug"));
        buttonSkipDebug->setGeometry(QRect(910, 730, 100, 25));
        buttonSkipDebug->setFont(font);
        stackedWidget->addWidget(pasScan);
        pincodeInvoeren = new QWidget();
        pincodeInvoeren->setObjectName(QStringLiteral("pincodeInvoeren"));
        pincodeInvoeren->setFont(font);
        pwPincode = new QLineEdit(pincodeInvoeren);
        pwPincode->setObjectName(QStringLiteral("pwPincode"));
        pwPincode->setGeometry(QRect(730, 264, 450, 151));
        QFont font5;
        font5.setFamily(QStringLiteral("Arial"));
        font5.setPointSize(36);
        font5.setStyleStrategy(QFont::PreferAntialias);
        pwPincode->setFont(font5);
        pwPincode->setLayoutDirection(Qt::LeftToRight);
        pwPincode->setStyleSheet(QLatin1String("qproperty-alignment: AlignCenter;\n"
"\n"
"background-color: rgb(186, 189, 182);"));
        pwPincode->setEchoMode(QLineEdit::Password);
        buttonPinCorrection = new QPushButton(pincodeInvoeren);
        buttonPinCorrection->setObjectName(QStringLiteral("buttonPinCorrection"));
        buttonPinCorrection->setGeometry(QRect(550, 560, 330, 100));
        buttonPinCorrection->setFont(font3);
        buttonPinConfirm = new QPushButton(pincodeInvoeren);
        buttonPinConfirm->setObjectName(QStringLiteral("buttonPinConfirm"));
        buttonPinConfirm->setGeometry(QRect(1040, 560, 332, 100));
        QFont font6;
        font6.setFamily(QStringLiteral("Arial"));
        font6.setPointSize(32);
        buttonPinConfirm->setFont(font6);
        labelPinError = new QLabel(pincodeInvoeren);
        labelPinError->setObjectName(QStringLiteral("labelPinError"));
        labelPinError->setGeometry(QRect(0, 40, 1920, 81));
        labelPinError->setFont(font4);
        labelPinError->setStyleSheet(QStringLiteral("color: rgb(164, 0, 0);"));
        labelPinError->setAlignment(Qt::AlignCenter);
        stackedWidget->addWidget(pincodeInvoeren);
        menu = new QWidget();
        menu->setObjectName(QStringLiteral("menu"));
        menu->setFont(font);
        buttonSaldo = new QPushButton(menu);
        buttonSaldo->setObjectName(QStringLiteral("buttonSaldo"));
        buttonSaldo->setGeometry(QRect(0, 190, 400, 150));
        buttonSaldo->setFont(font3);
        buttonOpnemen = new QPushButton(menu);
        buttonOpnemen->setObjectName(QStringLiteral("buttonOpnemen"));
        buttonOpnemen->setGeometry(QRect(0, 440, 400, 150));
        buttonOpnemen->setFont(font3);
        buttonSnel = new QPushButton(menu);
        buttonSnel->setObjectName(QStringLiteral("buttonSnel"));
        buttonSnel->setGeometry(QRect(1520, 190, 400, 150));
        buttonSnel->setFont(font3);
        labelMenuError = new QLabel(menu);
        labelMenuError->setObjectName(QStringLiteral("labelMenuError"));
        labelMenuError->setGeometry(QRect(0, 40, 1920, 81));
        labelMenuError->setFont(font4);
        labelMenuError->setStyleSheet(QStringLiteral("color: rgb(164, 0, 0);"));
        labelMenuError->setAlignment(Qt::AlignCenter);
        stackedWidget->addWidget(menu);
        saldo = new QWidget();
        saldo->setObjectName(QStringLiteral("saldo"));
        saldo->setFont(font);
        labelSaldoText = new QLabel(saldo);
        labelSaldoText->setObjectName(QStringLiteral("labelSaldoText"));
        labelSaldoText->setGeometry(QRect(660, 210, 600, 800));
        QFont font7;
        font7.setFamily(QStringLiteral("Arial"));
        font7.setPointSize(40);
        labelSaldoText->setFont(font7);
        labelSaldoText->setAlignment(Qt::AlignCenter);
        labelSaldo = new QLabel(saldo);
        labelSaldo->setObjectName(QStringLiteral("labelSaldo"));
        labelSaldo->setGeometry(QRect(335, 380, 1250, 201));
        QFont font8;
        font8.setFamily(QStringLiteral("Arial"));
        font8.setPointSize(110);
        labelSaldo->setFont(font8);
        labelSaldo->setAlignment(Qt::AlignCenter);
        stackedWidget->addWidget(saldo);
        opnemen = new QWidget();
        opnemen->setObjectName(QStringLiteral("opnemen"));
        opnemen->setFont(font);
        button20 = new QPushButton(opnemen);
        button20->setObjectName(QStringLiteral("button20"));
        button20->setGeometry(QRect(0, 30, 400, 150));
        button20->setFont(font3);
        button100 = new QPushButton(opnemen);
        button100->setObjectName(QStringLiteral("button100"));
        button100->setGeometry(QRect(0, 600, 400, 150));
        button100->setFont(font3);
        button500 = new QPushButton(opnemen);
        button500->setObjectName(QStringLiteral("button500"));
        button500->setGeometry(QRect(1520, 315, 400, 150));
        button500->setFont(font3);
        buttonAnders = new QPushButton(opnemen);
        buttonAnders->setObjectName(QStringLiteral("buttonAnders"));
        buttonAnders->setEnabled(true);
        buttonAnders->setGeometry(QRect(1520, 600, 400, 150));
        buttonAnders->setFont(font3);
        labelOpnemenError = new QLabel(opnemen);
        labelOpnemenError->setObjectName(QStringLiteral("labelOpnemenError"));
        labelOpnemenError->setGeometry(QRect(410, 40, 1100, 81));
        labelOpnemenError->setFont(font4);
        labelOpnemenError->setStyleSheet(QStringLiteral("color: rgb(164, 0, 0);"));
        labelOpnemenError->setAlignment(Qt::AlignCenter);
        button50 = new QPushButton(opnemen);
        button50->setObjectName(QStringLiteral("button50"));
        button50->setGeometry(QRect(0, 315, 400, 150));
        button50->setFont(font3);
        button200 = new QPushButton(opnemen);
        button200->setObjectName(QStringLiteral("button200"));
        button200->setGeometry(QRect(1520, 30, 400, 150));
        button200->setFont(font3);
        stackedWidget->addWidget(opnemen);
        bonKeuze = new QWidget();
        bonKeuze->setObjectName(QStringLiteral("bonKeuze"));
        bonKeuze->setFont(font);
        labelBon = new QLabel(bonKeuze);
        labelBon->setObjectName(QStringLiteral("labelBon"));
        labelBon->setGeometry(QRect(0, 40, 1920, 200));
        QFont font9;
        font9.setFamily(QStringLiteral("Arial"));
        font9.setPointSize(50);
        labelBon->setFont(font9);
        labelBon->setAlignment(Qt::AlignCenter);
        imgBon = new QLabel(bonKeuze);
        imgBon->setObjectName(QStringLiteral("imgBon"));
        imgBon->setGeometry(QRect(782, 140, 356, 478));
        imgBon->setFont(font);
        imgBon->setPixmap(QPixmap(QString::fromUtf8(":/Images/Resources/Images/pinbon.png")));
        imgBon->setScaledContents(true);
        imgBon->setAlignment(Qt::AlignCenter);
        buttonBonYes = new QPushButton(bonKeuze);
        buttonBonYes->setObjectName(QStringLiteral("buttonBonYes"));
        buttonBonYes->setGeometry(QRect(580, 650, 200, 100));
        buttonBonYes->setFont(font3);
        buttonBonNo = new QPushButton(bonKeuze);
        buttonBonNo->setObjectName(QStringLiteral("buttonBonNo"));
        buttonBonNo->setGeometry(QRect(1140, 650, 200, 100));
        buttonBonNo->setFont(font3);
        stackedWidget->addWidget(bonKeuze);
        anderBedrag = new QWidget();
        anderBedrag->setObjectName(QStringLiteral("anderBedrag"));
        anderBedrag->setFont(font);
        txtBedrag = new QLineEdit(anderBedrag);
        txtBedrag->setObjectName(QStringLiteral("txtBedrag"));
        txtBedrag->setGeometry(QRect(760, 275, 400, 170));
        txtBedrag->setFont(font5);
        txtBedrag->setLayoutDirection(Qt::LeftToRight);
        txtBedrag->setStyleSheet(QLatin1String("qproperty-alignment: AlignCenter;\n"
"\n"
"background-color: rgb(186, 189, 182);"));
        txtBedrag->setEchoMode(QLineEdit::Normal);
        labelDescription = new QLabel(anderBedrag);
        labelDescription->setObjectName(QStringLiteral("labelDescription"));
        labelDescription->setGeometry(QRect(0, 140, 1920, 71));
        QFont font10;
        font10.setFamily(QStringLiteral("Arial"));
        font10.setPointSize(24);
        labelDescription->setFont(font10);
        labelDescription->setAlignment(Qt::AlignCenter);
        labelAndersError = new QLabel(anderBedrag);
        labelAndersError->setObjectName(QStringLiteral("labelAndersError"));
        labelAndersError->setGeometry(QRect(0, 40, 1920, 81));
        QFont font11;
        font11.setFamily(QStringLiteral("Arial"));
        font11.setPointSize(29);
        font11.setBold(true);
        font11.setWeight(75);
        labelAndersError->setFont(font11);
        labelAndersError->setStyleSheet(QStringLiteral("color: rgb(164, 0, 0);"));
        labelAndersError->setAlignment(Qt::AlignCenter);
        buttonBedragCorrectie = new QPushButton(anderBedrag);
        buttonBedragCorrectie->setObjectName(QStringLiteral("buttonBedragCorrectie"));
        buttonBedragCorrectie->setGeometry(QRect(550, 540, 330, 100));
        buttonBedragCorrectie->setFont(font3);
        buttonBedragConfirm = new QPushButton(anderBedrag);
        buttonBedragConfirm->setObjectName(QStringLiteral("buttonBedragConfirm"));
        buttonBedragConfirm->setGeometry(QRect(1040, 540, 330, 100));
        buttonBedragConfirm->setFont(font6);
        stackedWidget->addWidget(anderBedrag);
        uitgifte = new QWidget();
        uitgifte->setObjectName(QStringLiteral("uitgifte"));
        uitgifte->setFont(font);
        labelOnthoudGeld = new QLabel(uitgifte);
        labelOnthoudGeld->setObjectName(QStringLiteral("labelOnthoudGeld"));
        labelOnthoudGeld->setGeometry(QRect(0, 20, 1920, 150));
        QFont font12;
        font12.setFamily(QStringLiteral("Arial"));
        font12.setPointSize(42);
        labelOnthoudGeld->setFont(font12);
        labelOnthoudGeld->setAlignment(Qt::AlignCenter);
        labelTotziens = new QLabel(uitgifte);
        labelTotziens->setObjectName(QStringLiteral("labelTotziens"));
        labelTotziens->setGeometry(QRect(0, 610, 1920, 150));
        labelTotziens->setFont(font12);
        labelTotziens->setAlignment(Qt::AlignCenter);
        imgUitgifte = new QLabel(uitgifte);
        imgUitgifte->setObjectName(QStringLiteral("imgUitgifte"));
        imgUitgifte->setGeometry(QRect(620, 180, 621, 421));
        imgUitgifte->setFont(font);
        imgUitgifte->setPixmap(QPixmap(QString::fromUtf8(":/Images/Resources/Images/takemoney.png")));
        imgUitgifte->setScaledContents(true);
        imgUitgifte->setAlignment(Qt::AlignCenter);
        buttonRestartDebug = new QPushButton(uitgifte);
        buttonRestartDebug->setObjectName(QStringLiteral("buttonRestartDebug"));
        buttonRestartDebug->setGeometry(QRect(900, 730, 120, 25));
        QFont font13;
        font13.setFamily(QStringLiteral("Arial"));
        font13.setPointSize(8);
        buttonRestartDebug->setFont(font13);
        stackedWidget->addWidget(uitgifte);
        Error = new QWidget();
        Error->setObjectName(QStringLiteral("Error"));
        Error->setFont(font);
        labelErrorMessage = new QLabel(Error);
        labelErrorMessage->setObjectName(QStringLiteral("labelErrorMessage"));
        labelErrorMessage->setGeometry(QRect(0, 250, 1920, 100));
        labelErrorMessage->setFont(font9);
        stackedWidget->addWidget(Error);
        labelTitle = new QLabel(MainWindow);
        labelTitle->setObjectName(QStringLiteral("labelTitle"));
        labelTitle->setGeometry(QRect(510, 0, 900, 200));
        labelTitle->setFont(font7);
        labelTitle->setStyleSheet(QStringLiteral("color: rgb(186, 189, 182);"));
        labelTitle->setAlignment(Qt::AlignCenter);
        buttonStop = new QPushButton(MainWindow);
        buttonStop->setObjectName(QStringLiteral("buttonStop"));
        buttonStop->setEnabled(true);
        buttonStop->setGeometry(QRect(1670, 980, 250, 100));
        QFont font14;
        font14.setFamily(QStringLiteral("Arial"));
        font14.setPointSize(30);
        buttonStop->setFont(font14);
        buttonStop->setStyleSheet(QStringLiteral("color: rgb(211, 215, 207);"));
        buttonBack = new QPushButton(MainWindow);
        buttonBack->setObjectName(QStringLiteral("buttonBack"));
        buttonBack->setEnabled(true);
        buttonBack->setGeometry(QRect(0, 980, 250, 100));
        buttonBack->setFont(font14);
        buttonBack->setStyleSheet(QStringLiteral("color: rgb(211, 215, 207);"));
        buttonBack->setCheckable(false);
        buttonBack->setChecked(false);
        saatbank = new QLabel(MainWindow);
        saatbank->setObjectName(QStringLiteral("saatbank"));
        saatbank->setGeometry(QRect(0, 49, 510, 151));
        saatbank->setPixmap(QPixmap(QString::fromUtf8(":/Images/Resources/Images/saatbank-logo.jpg")));
        saatbank->setScaledContents(true);
        saatbank->setAlignment(Qt::AlignCenter);
        saattext = new QLabel(MainWindow);
        saattext->setObjectName(QStringLiteral("saattext"));
        saattext->setGeometry(QRect(0, 0, 510, 49));
        QFont font15;
        font15.setPointSize(30);
        saattext->setFont(font15);
        saattext->setStyleSheet(QStringLiteral("color: rgb(186, 189, 182);"));

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QWidget *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "monc", Q_NULLPTR));
        buttonStart->setText(QApplication::translate("MainWindow", "Druk op een knop om door te gaan", Q_NULLPTR));
        moto->setText(QString());
        labelScan->setText(QString());
        imgScan->setText(QApplication::translate("MainWindow", "Houd uw pas tegen de scanner", Q_NULLPTR));
        labelScanError->setText(QString());
        buttonSkipDebug->setText(QApplication::translate("MainWindow", "Debug", Q_NULLPTR));
        pwPincode->setInputMask(QString());
        pwPincode->setText(QString());
        pwPincode->setPlaceholderText(QApplication::translate("MainWindow", "Pincode", Q_NULLPTR));
        buttonPinCorrection->setText(QApplication::translate("MainWindow", "A) Correctie", Q_NULLPTR));
        buttonPinConfirm->setText(QApplication::translate("MainWindow", "D) Bevestigen", Q_NULLPTR));
        labelPinError->setText(QString());
        buttonSaldo->setText(QApplication::translate("MainWindow", "A) Saldo", Q_NULLPTR));
        buttonOpnemen->setText(QApplication::translate("MainWindow", "B) Opnemen", Q_NULLPTR));
        buttonSnel->setText(QApplication::translate("MainWindow", "C) Snel \342\202\25470", Q_NULLPTR));
        labelMenuError->setText(QString());
        labelSaldoText->setText(QApplication::translate("MainWindow", "Uw huidige saldo is:", Q_NULLPTR));
        labelSaldo->setText(QApplication::translate("MainWindow", "-\342\202\2546.536.356,99", Q_NULLPTR));
        button20->setText(QApplication::translate("MainWindow", "1) \342\202\25420", Q_NULLPTR));
        button100->setText(QApplication::translate("MainWindow", "3) \342\202\254100", Q_NULLPTR));
        button500->setText(QApplication::translate("MainWindow", "5) \342\202\254500", Q_NULLPTR));
        buttonAnders->setText(QApplication::translate("MainWindow", "6) Anders", Q_NULLPTR));
        labelOpnemenError->setText(QString());
        button50->setText(QApplication::translate("MainWindow", "2) \342\202\25450", Q_NULLPTR));
        button200->setText(QApplication::translate("MainWindow", "4) \342\202\254200", Q_NULLPTR));
        labelBon->setText(QApplication::translate("MainWindow", "Wilt u de bon?", Q_NULLPTR));
        imgBon->setText(QString());
        buttonBonYes->setText(QApplication::translate("MainWindow", "A) Ja", Q_NULLPTR));
        buttonBonNo->setText(QApplication::translate("MainWindow", "D) Nee", Q_NULLPTR));
        txtBedrag->setText(QString());
        txtBedrag->setPlaceholderText(QApplication::translate("MainWindow", "Bedrag", Q_NULLPTR));
        labelDescription->setText(QApplication::translate("MainWindow", "Het bedrag moet een veelvoud zijn van 10 en mag niet hoger zijn dan 500", Q_NULLPTR));
        labelAndersError->setText(QString());
        buttonBedragCorrectie->setText(QApplication::translate("MainWindow", "A) Correctie", Q_NULLPTR));
        buttonBedragConfirm->setText(QApplication::translate("MainWindow", "D) Bevestigen", Q_NULLPTR));
        labelOnthoudGeld->setText(QApplication::translate("MainWindow", "Vergeet niet uw geld en eventueel bon uit te nemen", Q_NULLPTR));
        labelTotziens->setText(QApplication::translate("MainWindow", "Wij wensen u nog een fijne dag!", Q_NULLPTR));
        imgUitgifte->setText(QString());
        buttonRestartDebug->setText(QApplication::translate("MainWindow", "Restart", Q_NULLPTR));
        labelErrorMessage->setText(QString());
        labelTitle->setText(QApplication::translate("MainWindow", "Monc - MONEY FOR CORRUPTION", Q_NULLPTR));
        buttonStop->setText(QApplication::translate("MainWindow", "#) Stop", Q_NULLPTR));
        buttonBack->setText(QApplication::translate("MainWindow", "*) Terug", Q_NULLPTR));
        saatbank->setText(QString());
        saattext->setText(QApplication::translate("MainWindow", "Onderdeel van:", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
