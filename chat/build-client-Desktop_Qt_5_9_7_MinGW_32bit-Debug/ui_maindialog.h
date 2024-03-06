/********************************************************************************
** Form generated from reading UI file 'maindialog.ui'
**
** Created by: Qt User Interface Compiler version 5.9.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINDIALOG_H
#define UI_MAINDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_MainDialog
{
public:
    QLabel *label;
    QLabel *label_2;
    QComboBox *comboBox_ServerIP;
    QSpinBox *spinBox_ServerPort;
    QPushButton *pushButton_ConnectServer;
    QPushButton *pushButton_DidconnectServer;
    QPushButton *pushButton_Exit;
    QPushButton *pushButton_ClearMsg;
    QPushButton *pushButton_SendMsg;
    QGroupBox *groupBox;
    QGroupBox *groupBox_2;
    QPlainTextEdit *plainTextEdit_MsgList;
    QGroupBox *groupBox_3;
    QLabel *label_LocalIP;
    QPlainTextEdit *plainTextEdit_SendMsg;
    QGroupBox *groupBox_4;
    QPushButton *pushButton_SelectFile;
    QPushButton *pushButton_SendFile;
    QProgressBar *progressBar;

    void setupUi(QDialog *MainDialog)
    {
        if (MainDialog->objectName().isEmpty())
            MainDialog->setObjectName(QStringLiteral("MainDialog"));
        MainDialog->resize(1213, 835);
        QIcon icon;
        icon.addFile(QStringLiteral(":/new/prefix1/images/logo.ico"), QSize(), QIcon::Normal, QIcon::Off);
        MainDialog->setWindowIcon(icon);
        label = new QLabel(MainDialog);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(40, 50, 141, 31));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(12);
        label->setFont(font);
        label_2 = new QLabel(MainDialog);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(420, 50, 131, 31));
        label_2->setFont(font);
        comboBox_ServerIP = new QComboBox(MainDialog);
        comboBox_ServerIP->setObjectName(QStringLiteral("comboBox_ServerIP"));
        comboBox_ServerIP->setGeometry(QRect(190, 50, 201, 31));
        comboBox_ServerIP->setFont(font);
        comboBox_ServerIP->setEditable(true);
        spinBox_ServerPort = new QSpinBox(MainDialog);
        spinBox_ServerPort->setObjectName(QStringLiteral("spinBox_ServerPort"));
        spinBox_ServerPort->setGeometry(QRect(550, 50, 81, 31));
        spinBox_ServerPort->setFont(font);
        spinBox_ServerPort->setMaximum(65535);
        spinBox_ServerPort->setValue(6688);
        pushButton_ConnectServer = new QPushButton(MainDialog);
        pushButton_ConnectServer->setObjectName(QStringLiteral("pushButton_ConnectServer"));
        pushButton_ConnectServer->setGeometry(QRect(700, 50, 191, 31));
        pushButton_ConnectServer->setFont(font);
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/new/prefix1/images/connect.ico"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_ConnectServer->setIcon(icon1);
        pushButton_DidconnectServer = new QPushButton(MainDialog);
        pushButton_DidconnectServer->setObjectName(QStringLiteral("pushButton_DidconnectServer"));
        pushButton_DidconnectServer->setGeometry(QRect(960, 50, 191, 31));
        pushButton_DidconnectServer->setFont(font);
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/new/prefix1/images/disconnect.ico"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_DidconnectServer->setIcon(icon2);
        pushButton_Exit = new QPushButton(MainDialog);
        pushButton_Exit->setObjectName(QStringLiteral("pushButton_Exit"));
        pushButton_Exit->setGeometry(QRect(440, 550, 191, 31));
        pushButton_Exit->setFont(font);
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/new/prefix1/images/exit.ico"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_Exit->setIcon(icon3);
        pushButton_ClearMsg = new QPushButton(MainDialog);
        pushButton_ClearMsg->setObjectName(QStringLiteral("pushButton_ClearMsg"));
        pushButton_ClearMsg->setGeometry(QRect(700, 550, 191, 31));
        pushButton_ClearMsg->setFont(font);
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/new/prefix1/images/clear.ico"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_ClearMsg->setIcon(icon4);
        pushButton_SendMsg = new QPushButton(MainDialog);
        pushButton_SendMsg->setObjectName(QStringLiteral("pushButton_SendMsg"));
        pushButton_SendMsg->setGeometry(QRect(960, 550, 191, 31));
        pushButton_SendMsg->setFont(font);
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/new/prefix1/images/sendmsg.ico"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_SendMsg->setIcon(icon5);
        groupBox = new QGroupBox(MainDialog);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(20, 20, 1151, 91));
        groupBox_2 = new QGroupBox(MainDialog);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(20, 130, 1151, 241));
        groupBox_2->setFont(font);
        plainTextEdit_MsgList = new QPlainTextEdit(groupBox_2);
        plainTextEdit_MsgList->setObjectName(QStringLiteral("plainTextEdit_MsgList"));
        plainTextEdit_MsgList->setGeometry(QRect(20, 40, 1111, 171));
        groupBox_3 = new QGroupBox(MainDialog);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setGeometry(QRect(20, 390, 1151, 221));
        groupBox_3->setFont(font);
        label_LocalIP = new QLabel(groupBox_3);
        label_LocalIP->setObjectName(QStringLiteral("label_LocalIP"));
        label_LocalIP->setGeometry(QRect(20, 160, 531, 31));
        plainTextEdit_SendMsg = new QPlainTextEdit(groupBox_3);
        plainTextEdit_SendMsg->setObjectName(QStringLiteral("plainTextEdit_SendMsg"));
        plainTextEdit_SendMsg->setGeometry(QRect(20, 40, 1111, 91));
        groupBox_4 = new QGroupBox(MainDialog);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        groupBox_4->setGeometry(QRect(20, 630, 1151, 171));
        groupBox_4->setFont(font);
        pushButton_SelectFile = new QPushButton(groupBox_4);
        pushButton_SelectFile->setObjectName(QStringLiteral("pushButton_SelectFile"));
        pushButton_SelectFile->setGeometry(QRect(680, 40, 191, 31));
        pushButton_SelectFile->setFont(font);
        QIcon icon6;
        icon6.addFile(QStringLiteral(":/new/prefix1/images/openfile.ico"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_SelectFile->setIcon(icon6);
        pushButton_SendFile = new QPushButton(groupBox_4);
        pushButton_SendFile->setObjectName(QStringLiteral("pushButton_SendFile"));
        pushButton_SendFile->setGeometry(QRect(940, 40, 191, 31));
        pushButton_SendFile->setFont(font);
        QIcon icon7;
        icon7.addFile(QStringLiteral(":/new/prefix1/images/sendfile.ico"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_SendFile->setIcon(icon7);
        progressBar = new QProgressBar(groupBox_4);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        progressBar->setGeometry(QRect(20, 110, 1111, 31));
        progressBar->setFont(font);
        progressBar->setValue(0);
        groupBox_4->raise();
        groupBox_3->raise();
        groupBox_2->raise();
        groupBox->raise();
        label->raise();
        label_2->raise();
        comboBox_ServerIP->raise();
        spinBox_ServerPort->raise();
        pushButton_ConnectServer->raise();
        pushButton_DidconnectServer->raise();
        pushButton_Exit->raise();
        pushButton_ClearMsg->raise();
        pushButton_SendMsg->raise();

        retranslateUi(MainDialog);

        QMetaObject::connectSlotsByName(MainDialog);
    } // setupUi

    void retranslateUi(QDialog *MainDialog)
    {
        MainDialog->setWindowTitle(QApplication::translate("MainDialog", "\345\256\242\346\210\267\347\253\257\344\270\216\346\234\215\345\212\241\345\231\250\346\236\266\346\236\204\347\263\273\347\273\237-TCP\345\256\242\346\210\267\347\253\257version1.0", Q_NULLPTR));
        label->setText(QApplication::translate("MainDialog", "<html><head/><body><p>\346\234\215\345\212\241\345\231\250IP\345\234\260\345\235\200</p></body></html>", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainDialog", "\346\234\215\345\212\241\345\231\250\347\253\257\345\217\243", Q_NULLPTR));
        comboBox_ServerIP->clear();
        comboBox_ServerIP->insertItems(0, QStringList()
         << QApplication::translate("MainDialog", "127.0.0.1", Q_NULLPTR)
        );
        pushButton_ConnectServer->setText(QApplication::translate("MainDialog", "\350\277\236\346\216\245\346\234\215\345\212\241\345\231\250", Q_NULLPTR));
        pushButton_DidconnectServer->setText(QApplication::translate("MainDialog", "\346\226\255\345\274\200\346\234\215\345\212\241\345\231\250", Q_NULLPTR));
        pushButton_Exit->setText(QApplication::translate("MainDialog", "\351\200\200\345\207\272\347\263\273\347\273\237", Q_NULLPTR));
        pushButton_ClearMsg->setText(QApplication::translate("MainDialog", "\346\270\205\351\231\244\346\266\210\346\201\257", Q_NULLPTR));
        pushButton_SendMsg->setText(QApplication::translate("MainDialog", "\345\217\221\351\200\201\346\266\210\346\201\257", Q_NULLPTR));
        groupBox->setTitle(QString());
        groupBox_2->setTitle(QApplication::translate("MainDialog", "\346\266\210\346\201\257\345\210\227\350\241\250", Q_NULLPTR));
        groupBox_3->setTitle(QApplication::translate("MainDialog", "\345\217\221\351\200\201\346\266\210\346\201\257", Q_NULLPTR));
        label_LocalIP->setText(QApplication::translate("MainDialog", "\346\234\254\346\234\272IP\345\234\260\345\235\200", Q_NULLPTR));
        groupBox_4->setTitle(QApplication::translate("MainDialog", "\344\274\240\350\276\223\346\226\207\344\273\266\350\207\263\346\234\215\345\212\241\345\231\250", Q_NULLPTR));
        pushButton_SelectFile->setText(QApplication::translate("MainDialog", "\351\200\211\346\213\251\346\226\207\344\273\266", Q_NULLPTR));
        pushButton_SendFile->setText(QApplication::translate("MainDialog", "\345\217\221\351\200\201\346\226\207\344\273\266", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainDialog: public Ui_MainDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINDIALOG_H
