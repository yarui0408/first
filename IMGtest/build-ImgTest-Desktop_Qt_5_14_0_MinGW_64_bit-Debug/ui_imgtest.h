/********************************************************************************
** Form generated from reading UI file 'imgtest.ui'
**
** Created by: Qt User Interface Compiler version 5.14.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_IMGTEST_H
#define UI_IMGTEST_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ImgTest
{
public:
    QLabel *label;
    QPushButton *pushButton;
    QTextBrowser *textBrowser;
    QComboBox *comboBox;
    QLabel *labelGame;

    void setupUi(QWidget *ImgTest)
    {
        if (ImgTest->objectName().isEmpty())
            ImgTest->setObjectName(QString::fromUtf8("ImgTest"));
        ImgTest->resize(975, 700);
        label = new QLabel(ImgTest);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(130, 210, 350, 450));
        label->setMinimumSize(QSize(0, 0));
        label->setMaximumSize(QSize(90000, 90000));
        label->setScaledContents(true);
        pushButton = new QPushButton(ImgTest);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(130, 120, 350, 50));
        pushButton->setMinimumSize(QSize(350, 50));
        pushButton->setMaximumSize(QSize(350, 50));
        textBrowser = new QTextBrowser(ImgTest);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        textBrowser->setGeometry(QRect(660, 270, 250, 300));
        textBrowser->setMinimumSize(QSize(250, 300));
        textBrowser->setMaximumSize(QSize(250, 300));
        QFont font;
        font.setFamily(QString::fromUtf8("Arial"));
        font.setPointSize(14);
        textBrowser->setFont(font);
        comboBox = new QComboBox(ImgTest);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(610, 610, 350, 50));
        comboBox->setMinimumSize(QSize(350, 50));
        comboBox->setMaximumSize(QSize(350, 50));
        QFont font1;
        font1.setPointSize(25);
        comboBox->setFont(font1);
        labelGame = new QLabel(ImgTest);
        labelGame->setObjectName(QString::fromUtf8("labelGame"));
        labelGame->setGeometry(QRect(140, 50, 341, 41));
        QFont font2;
        font2.setPointSize(15);
        labelGame->setFont(font2);

        retranslateUi(ImgTest);

        QMetaObject::connectSlotsByName(ImgTest);
    } // setupUi

    void retranslateUi(QWidget *ImgTest)
    {
        ImgTest->setWindowTitle(QCoreApplication::translate("ImgTest", "ImgTest", nullptr));
        label->setText(QCoreApplication::translate("ImgTest", "<html><head/><body><p align=\"center\"><br/></p></body></html>", nullptr));
        pushButton->setText(QCoreApplication::translate("ImgTest", "\345\206\215\346\235\245\344\270\200\346\254\241", nullptr));
        labelGame->setText(QCoreApplication::translate("ImgTest", "<html><head/><body><p align=\"center\">TextLabel</p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ImgTest: public Ui_ImgTest {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_IMGTEST_H
