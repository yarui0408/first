/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QLabel *label_DisplaySongTitle;
    QGroupBox *groupBox_3;
    QPushButton *pushButton_AddSong;
    QPushButton *pushButton_PlaySong;
    QPushButton *pushButton_PreviousSong;
    QPushButton *pushButton_PauseSong;
    QPushButton *pushButton_StopPlaySong;
    QPushButton *pushButton_PlayNextSong;
    QSlider *horizontalSlider_PlayProgress;
    QSlider *horizontalSlider_Volume;
    QPushButton *pushButton_SoundYesNo;
    QLCDNumber *lcdNumber_PlayTime;
    QGroupBox *groupBox_2;
    QPlainTextEdit *plainTextEdit_SongList;
    QGroupBox *groupBox;
    QPushButton *pushButton_St;
    QLineEdit *lineEdit_InputSongs;
    QPushButton *pushButton_SearchSong;
    QPushButton *pushButton_About;
    QPushButton *pushButton_Exit;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(905, 654);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        label_DisplaySongTitle = new QLabel(centralWidget);
        label_DisplaySongTitle->setObjectName(QStringLiteral("label_DisplaySongTitle"));
        label_DisplaySongTitle->setGeometry(QRect(0, 0, 791, 31));
        groupBox_3 = new QGroupBox(centralWidget);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setGeometry(QRect(0, 480, 891, 101));
        pushButton_AddSong = new QPushButton(groupBox_3);
        pushButton_AddSong->setObjectName(QStringLiteral("pushButton_AddSong"));
        pushButton_AddSong->setGeometry(QRect(30, 60, 31, 31));
        pushButton_AddSong->setStyleSheet(QStringLiteral("background-color:rgb(255,255,255,0)"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/new/prefix1/images/MOpenSong.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_AddSong->setIcon(icon);
        pushButton_PlaySong = new QPushButton(groupBox_3);
        pushButton_PlaySong->setObjectName(QStringLiteral("pushButton_PlaySong"));
        pushButton_PlaySong->setGeometry(QRect(110, 60, 31, 31));
        pushButton_PlaySong->setStyleSheet(QStringLiteral("background-color:rgb(255,255,255,0)"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/new/prefix1/images/MPlay.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_PlaySong->setIcon(icon1);
        pushButton_PreviousSong = new QPushButton(groupBox_3);
        pushButton_PreviousSong->setObjectName(QStringLiteral("pushButton_PreviousSong"));
        pushButton_PreviousSong->setGeometry(QRect(350, 60, 31, 31));
        pushButton_PreviousSong->setStyleSheet(QStringLiteral("background-color:rgb(255,255,255,0)"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/new/prefix1/images/MPrevious.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_PreviousSong->setIcon(icon2);
        pushButton_PauseSong = new QPushButton(groupBox_3);
        pushButton_PauseSong->setObjectName(QStringLiteral("pushButton_PauseSong"));
        pushButton_PauseSong->setGeometry(QRect(190, 60, 31, 31));
        pushButton_PauseSong->setStyleSheet(QStringLiteral("background-color:rgb(255,255,255,0)"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/new/prefix1/images/MPause.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_PauseSong->setIcon(icon3);
        pushButton_StopPlaySong = new QPushButton(groupBox_3);
        pushButton_StopPlaySong->setObjectName(QStringLiteral("pushButton_StopPlaySong"));
        pushButton_StopPlaySong->setGeometry(QRect(270, 60, 31, 31));
        pushButton_StopPlaySong->setStyleSheet(QStringLiteral("background-color:rgb(255,255,255,0)"));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/new/prefix1/images/MStops.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_StopPlaySong->setIcon(icon4);
        pushButton_PlayNextSong = new QPushButton(groupBox_3);
        pushButton_PlayNextSong->setObjectName(QStringLiteral("pushButton_PlayNextSong"));
        pushButton_PlayNextSong->setGeometry(QRect(430, 60, 31, 31));
        pushButton_PlayNextSong->setStyleSheet(QStringLiteral("background-color:rgb(255,255,255,0)"));
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/new/prefix1/images/MNext.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_PlayNextSong->setIcon(icon5);
        horizontalSlider_PlayProgress = new QSlider(groupBox_3);
        horizontalSlider_PlayProgress->setObjectName(QStringLiteral("horizontalSlider_PlayProgress"));
        horizontalSlider_PlayProgress->setGeometry(QRect(20, 20, 741, 31));
        horizontalSlider_PlayProgress->setOrientation(Qt::Horizontal);
        horizontalSlider_Volume = new QSlider(groupBox_3);
        horizontalSlider_Volume->setObjectName(QStringLiteral("horizontalSlider_Volume"));
        horizontalSlider_Volume->setGeometry(QRect(510, 60, 251, 31));
        horizontalSlider_Volume->setOrientation(Qt::Horizontal);
        pushButton_SoundYesNo = new QPushButton(groupBox_3);
        pushButton_SoundYesNo->setObjectName(QStringLiteral("pushButton_SoundYesNo"));
        pushButton_SoundYesNo->setGeometry(QRect(850, 60, 31, 31));
        pushButton_SoundYesNo->setStyleSheet(QStringLiteral("background-color:rgb(255,255,255,0)"));
        QIcon icon6;
        icon6.addFile(QStringLiteral(":/new/prefix1/images/MSound.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_SoundYesNo->setIcon(icon6);
        lcdNumber_PlayTime = new QLCDNumber(groupBox_3);
        lcdNumber_PlayTime->setObjectName(QStringLiteral("lcdNumber_PlayTime"));
        lcdNumber_PlayTime->setGeometry(QRect(810, 10, 71, 41));
        lcdNumber_PlayTime->setStyleSheet(QStringLiteral("background-color:rgb(255,255,255,0)"));
        groupBox_2 = new QGroupBox(centralWidget);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(0, 130, 891, 321));
        groupBox_2->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        plainTextEdit_SongList = new QPlainTextEdit(centralWidget);
        plainTextEdit_SongList->setObjectName(QStringLiteral("plainTextEdit_SongList"));
        plainTextEdit_SongList->setGeometry(QRect(10, 160, 871, 271));
        plainTextEdit_SongList->setStyleSheet(QStringLiteral("background-color:rgb(255,255,255,70)"));
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(0, 40, 891, 71));
        pushButton_St = new QPushButton(groupBox);
        pushButton_St->setObjectName(QStringLiteral("pushButton_St"));
        pushButton_St->setGeometry(QRect(10, 20, 151, 31));
        pushButton_St->setStyleSheet(QStringLiteral("background-color:rgb(255,255,255,70)"));
        QIcon icon7;
        icon7.addFile(QStringLiteral(":/new/prefix1/images/MDriect.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_St->setIcon(icon7);
        lineEdit_InputSongs = new QLineEdit(groupBox);
        lineEdit_InputSongs->setObjectName(QStringLiteral("lineEdit_InputSongs"));
        lineEdit_InputSongs->setGeometry(QRect(180, 20, 541, 31));
        lineEdit_InputSongs->setStyleSheet(QStringLiteral("background-color:rgb(255,255,255,70)"));
        pushButton_SearchSong = new QPushButton(groupBox);
        pushButton_SearchSong->setObjectName(QStringLiteral("pushButton_SearchSong"));
        pushButton_SearchSong->setGeometry(QRect(740, 20, 141, 31));
        pushButton_SearchSong->setStyleSheet(QStringLiteral(""));
        QIcon icon8;
        icon8.addFile(QStringLiteral(":/new/prefix1/images/MSerach.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_SearchSong->setIcon(icon8);
        pushButton_About = new QPushButton(centralWidget);
        pushButton_About->setObjectName(QStringLiteral("pushButton_About"));
        pushButton_About->setGeometry(QRect(800, 0, 41, 31));
        pushButton_About->setStyleSheet(QStringLiteral("background-color:rgb(255,255,255,0)"));
        QIcon icon9;
        icon9.addFile(QStringLiteral(":/new/prefix1/images/MAbout.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_About->setIcon(icon9);
        pushButton_Exit = new QPushButton(centralWidget);
        pushButton_Exit->setObjectName(QStringLiteral("pushButton_Exit"));
        pushButton_Exit->setGeometry(QRect(850, 0, 41, 31));
        pushButton_Exit->setStyleSheet(QStringLiteral("background-color:rgb(255,255,255,0)"));
        QIcon icon10;
        icon10.addFile(QStringLiteral(":/new/prefix1/images/MQuit.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_Exit->setIcon(icon10);
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 905, 17));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        label_DisplaySongTitle->setText(QString());
        groupBox_3->setTitle(QString());
        pushButton_AddSong->setText(QString());
        pushButton_PlaySong->setText(QString());
        pushButton_PreviousSong->setText(QString());
        pushButton_PauseSong->setText(QString());
        pushButton_StopPlaySong->setText(QString());
        pushButton_PlayNextSong->setText(QString());
        pushButton_SoundYesNo->setText(QString());
        groupBox_2->setTitle(QApplication::translate("MainWindow", "\345\234\250\347\272\277\351\237\263\344\271\220\345\210\227\350\241\250", Q_NULLPTR));
        groupBox->setTitle(QString());
        pushButton_St->setText(QApplication::translate("MainWindow", "\345\212\250\346\211\213\346\220\234\344\270\200\346\220\234", Q_NULLPTR));
        pushButton_SearchSong->setText(QApplication::translate("MainWindow", "Search...", Q_NULLPTR));
        pushButton_About->setText(QString());
        pushButton_Exit->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
