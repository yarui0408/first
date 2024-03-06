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
    QGroupBox *groupBox;
    QLabel *label_server;
    QLabel *label_port;
    QSpinBox *spinBox_ClientPort;
    QComboBox *comboBox_ClientIP;
    QPushButton *pushButton_StartListening;
    QPushButton *pushButton_StopListening;
    QGroupBox *groupBox_2;
    QPlainTextEdit *plainTextEdit_MsgList;
    QGroupBox *groupBox_3;
    QPlainTextEdit *plainTextEdit_SendList;
    QPushButton *pushButton_SendData;
    QPushButton *pushButton_ClearMsg;
    QPushButton *pushButton_ExitSystem;
    QLabel *label_LocalIP;
    QLabel *label_3;
    QProgressBar *progressBar;

    void setupUi(QDialog *MainDialog)
    {
        if (MainDialog->objectName().isEmpty())
            MainDialog->setObjectName(QStringLiteral("MainDialog"));
        MainDialog->resize(1279, 649);
        QFont font;
        font.setPointSize(12);
        MainDialog->setFont(font);
        QIcon icon;
        icon.addFile(QStringLiteral(":/new/prefix1/images/logo.ico"), QSize(), QIcon::Normal, QIcon::Off);
        MainDialog->setWindowIcon(icon);
        groupBox = new QGroupBox(MainDialog);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(10, 20, 1221, 81));
        label_server = new QLabel(groupBox);
        label_server->setObjectName(QStringLiteral("label_server"));
        label_server->setGeometry(QRect(20, 30, 281, 31));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        label_server->setFont(font1);
        label_port = new QLabel(groupBox);
        label_port->setObjectName(QStringLiteral("label_port"));
        label_port->setGeometry(QRect(420, 30, 251, 31));
        label_port->setFont(font1);
        spinBox_ClientPort = new QSpinBox(groupBox);
        spinBox_ClientPort->setObjectName(QStringLiteral("spinBox_ClientPort"));
        spinBox_ClientPort->setGeometry(QRect(600, 30, 81, 31));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font2.setPointSize(12);
        spinBox_ClientPort->setFont(font2);
        spinBox_ClientPort->setMaximum(65535);
        spinBox_ClientPort->setValue(6688);
        comboBox_ClientIP = new QComboBox(groupBox);
        comboBox_ClientIP->setObjectName(QStringLiteral("comboBox_ClientIP"));
        comboBox_ClientIP->setGeometry(QRect(200, 30, 171, 31));
        pushButton_StartListening = new QPushButton(groupBox);
        pushButton_StartListening->setObjectName(QStringLiteral("pushButton_StartListening"));
        pushButton_StartListening->setGeometry(QRect(750, 30, 191, 31));
        pushButton_StartListening->setFont(font1);
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/new/prefix1/images/start.ico"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_StartListening->setIcon(icon1);
        pushButton_StopListening = new QPushButton(groupBox);
        pushButton_StopListening->setObjectName(QStringLiteral("pushButton_StopListening"));
        pushButton_StopListening->setGeometry(QRect(1010, 30, 191, 31));
        pushButton_StopListening->setFont(font1);
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/new/prefix1/images/stop.ico"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_StopListening->setIcon(icon2);
        groupBox_2 = new QGroupBox(MainDialog);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(10, 120, 1221, 211));
        groupBox_2->setFont(font2);
        plainTextEdit_MsgList = new QPlainTextEdit(groupBox_2);
        plainTextEdit_MsgList->setObjectName(QStringLiteral("plainTextEdit_MsgList"));
        plainTextEdit_MsgList->setGeometry(QRect(20, 40, 1181, 141));
        groupBox_3 = new QGroupBox(MainDialog);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setGeometry(QRect(10, 350, 1221, 201));
        groupBox_3->setFont(font2);
        plainTextEdit_SendList = new QPlainTextEdit(groupBox_3);
        plainTextEdit_SendList->setObjectName(QStringLiteral("plainTextEdit_SendList"));
        plainTextEdit_SendList->setGeometry(QRect(20, 40, 1181, 71));
        pushButton_SendData = new QPushButton(groupBox_3);
        pushButton_SendData->setObjectName(QStringLiteral("pushButton_SendData"));
        pushButton_SendData->setGeometry(QRect(1010, 140, 191, 31));
        pushButton_SendData->setFont(font1);
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/new/prefix1/images/sendmsg.ico"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_SendData->setIcon(icon3);
        pushButton_ClearMsg = new QPushButton(groupBox_3);
        pushButton_ClearMsg->setObjectName(QStringLiteral("pushButton_ClearMsg"));
        pushButton_ClearMsg->setGeometry(QRect(750, 140, 191, 31));
        pushButton_ClearMsg->setFont(font1);
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/new/prefix1/images/clear.ico"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_ClearMsg->setIcon(icon4);
        pushButton_ExitSystem = new QPushButton(groupBox_3);
        pushButton_ExitSystem->setObjectName(QStringLiteral("pushButton_ExitSystem"));
        pushButton_ExitSystem->setGeometry(QRect(490, 140, 191, 31));
        pushButton_ExitSystem->setFont(font1);
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/new/prefix1/images/exit.ico"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_ExitSystem->setIcon(icon5);
        label_LocalIP = new QLabel(groupBox_3);
        label_LocalIP->setObjectName(QStringLiteral("label_LocalIP"));
        label_LocalIP->setGeometry(QRect(20, 140, 281, 31));
        label_LocalIP->setFont(font1);
        label_3 = new QLabel(MainDialog);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(30, 580, 281, 31));
        label_3->setFont(font1);
        progressBar = new QProgressBar(MainDialog);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        progressBar->setGeometry(QRect(200, 580, 1011, 31));
        progressBar->setValue(24);
        groupBox_2->raise();
        groupBox->raise();
        groupBox_3->raise();
        label_3->raise();
        progressBar->raise();

        retranslateUi(MainDialog);

        QMetaObject::connectSlotsByName(MainDialog);
    } // setupUi

    void retranslateUi(QDialog *MainDialog)
    {
        MainDialog->setWindowTitle(QApplication::translate("MainDialog", "\345\256\242\346\210\267\347\253\257\344\270\216\346\234\215\345\212\241\345\231\250\346\236\266\346\236\204\347\263\273\347\273\237-TCP\346\234\215\345\212\241\345\231\250", Q_NULLPTR));
        groupBox->setTitle(QString());
        label_server->setText(QApplication::translate("MainDialog", "<html><head/><body><p><span style=\" font-size:12pt;\">\346\234\215\345\212\241\345\231\250\347\233\221\345\220\254\345\234\260\345\235\200</span></p></body></html>", Q_NULLPTR));
        label_port->setText(QApplication::translate("MainDialog", "<html><head/><body><p><span style=\" font-size:12pt;\">\346\234\215\345\212\241\345\231\250\347\233\221\345\220\254\347\253\257\345\217\243</span></p></body></html>", Q_NULLPTR));
        comboBox_ClientIP->clear();
        comboBox_ClientIP->insertItems(0, QStringList()
         << QApplication::translate("MainDialog", "127.0.0.1", Q_NULLPTR)
        );
        pushButton_StartListening->setText(QApplication::translate("MainDialog", "\345\220\257\345\212\250\347\233\221\345\220\254", Q_NULLPTR));
        pushButton_StopListening->setText(QApplication::translate("MainDialog", "\345\201\234\346\255\242\347\233\221\345\220\254", Q_NULLPTR));
        groupBox_2->setTitle(QApplication::translate("MainDialog", "\346\266\210\346\201\257\345\210\227\350\241\250", Q_NULLPTR));
        groupBox_3->setTitle(QApplication::translate("MainDialog", "\345\217\221\351\200\201\346\266\210\346\201\257", Q_NULLPTR));
        pushButton_SendData->setText(QApplication::translate("MainDialog", "\345\217\221\351\200\201\346\266\210\346\201\257", Q_NULLPTR));
        pushButton_ClearMsg->setText(QApplication::translate("MainDialog", "\346\270\205\351\231\244\346\266\210\346\201\257", Q_NULLPTR));
        pushButton_ExitSystem->setText(QApplication::translate("MainDialog", "\351\200\200\345\207\272\347\263\273\347\273\237", Q_NULLPTR));
        label_LocalIP->setText(QApplication::translate("MainDialog", "<html><head/><body><p>\346\234\254\346\234\272IP\345\234\260\345\235\200\357\274\232</p></body></html>", Q_NULLPTR));
        label_3->setText(QApplication::translate("MainDialog", "<html><head/><body><p>\346\216\245\346\224\266\346\226\207\344\273\266\350\277\233\345\272\246\357\274\232</p></body></html>", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainDialog: public Ui_MainDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINDIALOG_H
