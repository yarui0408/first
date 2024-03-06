/********************************************************************************
** Form generated from reading UI file 'aboutdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.9.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ABOUTDIALOG_H
#define UI_ABOUTDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_AboutDialog
{
public:
    QLabel *label;
    QLabel *label_2;
    QPushButton *pushButton_closew;
    QGroupBox *groupBox;

    void setupUi(QDialog *AboutDialog)
    {
        if (AboutDialog->objectName().isEmpty())
            AboutDialog->setObjectName(QStringLiteral("AboutDialog"));
        AboutDialog->resize(520, 441);
        label = new QLabel(AboutDialog);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(80, 160, 71, 91));
        label->setStyleSheet(QStringLiteral(""));
        label->setPixmap(QPixmap(QString::fromUtf8(":/new/prefix1/images/logo.png")));
        label_2 = new QLabel(AboutDialog);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(170, 100, 331, 221));
        label_2->setStyleSheet(QStringLiteral(""));
        pushButton_closew = new QPushButton(AboutDialog);
        pushButton_closew->setObjectName(QStringLiteral("pushButton_closew"));
        pushButton_closew->setGeometry(QRect(400, 360, 81, 31));
        pushButton_closew->setStyleSheet(QStringLiteral("background-color:rgb(255,255,255,70)"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/new/prefix1/images/MClose.ico"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_closew->setIcon(icon);
        groupBox = new QGroupBox(AboutDialog);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(10, 100, 491, 221));
        groupBox->setStyleSheet(QStringLiteral("background-color:rgb(255,255,255,70)"));
        groupBox->raise();
        label->raise();
        label_2->raise();
        pushButton_closew->raise();

        retranslateUi(AboutDialog);

        QMetaObject::connectSlotsByName(AboutDialog);
    } // setupUi

    void retranslateUi(QDialog *AboutDialog)
    {
        AboutDialog->setWindowTitle(QApplication::translate("AboutDialog", "Dialog", Q_NULLPTR));
        label->setText(QString());
        label_2->setText(QApplication::translate("AboutDialog", "<html><head/><body><p><span style=\" color:#ffffff;\">MP3\351\237\263\344\271\220\346\222\255\346\224\276\345\231\250\346\220\234\347\264\242\345\274\225\346\223\216</span></p><p><span style=\" color:#ffffff;\">\344\275\234\350\200\205:yarui</span></p><p><span style=\" color:#ffffff;\">\346\222\255\346\224\276\345\231\250\345\212\237\350\203\275\345\246\202\344\270\213\357\274\232</span></p><p><span style=\" color:#ffffff;\">1\357\274\232\345\234\250\347\272\277\346\220\234\347\264\242\351\237\263\344\271\220\346\222\255\346\224\276\345\212\237\350\203\275</span></p><p><span style=\" color:#ffffff;\">2\357\274\232\346\211\223\345\274\200\346\234\254\345\234\260\351\237\263\344\271\220\346\222\255\346\224\276\345\212\237\350\203\275</span></p><p><span style=\" color:#ffffff;\">3\357\274\232\346\222\255\346\224\276/\346\232\202\345\201\234/\345\201\234\346\255\242/\344\270\212\344\270\200\346\233\262/\344\270\213\344\270\200\346\233\262</span></p></body></html>", Q_NULLPTR));
        pushButton_closew->setText(QApplication::translate("AboutDialog", "\345\205\263\351\227\255", Q_NULLPTR));
        groupBox->setTitle(QString());
    } // retranslateUi

};

namespace Ui {
    class AboutDialog: public Ui_AboutDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ABOUTDIALOG_H
