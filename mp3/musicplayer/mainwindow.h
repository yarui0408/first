#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>








#include"aboutdialog.h"
#include<QPainter>
#include<QRect>
#include<QMessageBox>

#include<QNetworkAccessManager>
#include<QNetworkReply>

#include<QMediaPlayer>
#include<QMediaPlaylist>

#include<QTextBlock>
#include<QTimer>
#include<QFileDialog>

#include<QJsonParseError>
#include<QJsonArray>


#include<QJsonObject>






namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();






public:



    //处理窗口重绘背景图片
     void paintEvent(QPaintEvent *event);

     //功能：使用鼠标拖动窗口移动MP3播放器到桌面的任意位置
     void mousePressEvent(QMouseEvent *event);
     void mouseMoveEvent(QMouseEvent *event);
     void mouseReleaseEvent(QMouseEvent *event);


     QByteArray QByteArySearchInfo;//存储搜索返回数据信息
     bool m_MouseDrag;
     QPoint mouseStartPoint;
     QPoint windowStartPoint;

     //歌曲ID
     int I_MusicID;
     //歌曲名称、歌手姓名
     QString StrMusicName,StrSingerName;


     QTextBlock *qTextLine;//处理文本块指针

     QMediaPlayer *p_PlayerObject;//定义多媒体播放器
     QMediaPlaylist *p_PlayerList;//定义多媒体播放列表

     QNetworkAccessManager *NetworkAccessManagers;
     int iPlayFlags;//标记播放状态
     QTextDocument *docTextObject;//处理文本信息




     //处理动态字幕
     QString strTitles;
     int iTitleChar;











public slots:
     //处理lcdnumber控件时间变化
     void HandleLCDNumberTimeChangeFunc(qint64 SongDuration);
     //处理播放位置变化
     void HandlePositionChangeFunc(qint64 position);
     //处理进度条控件变化
     void HandleProgressTimeChangeFunc(qint64 SongDuration);
     //处理数据信息返回函数
     void HandleDataBackFunc(QNetworkReply *pReply);
     //实现字幕动态变化
     void titleMoveCaptionChar();











private slots:
     void on_pushButton_Exit_clicked();

     void on_pushButton_About_clicked();

     void on_pushButton_AddSong_clicked();

     void on_pushButton_PlaySong_clicked();

     void on_pushButton_PauseSong_clicked();

     void on_pushButton_StopPlaySong_clicked();

     void on_pushButton_PreviousSong_clicked();

     void on_pushButton_PlayNextSong_clicked();

     void on_pushButton_SearchSong_clicked();

     void on_pushButton_SoundYesNo_clicked();

     void on_horizontalSlider_Volume_valueChanged(int value);

     void on_horizontalSlider_PlayProgress_valueChanged(int value);

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
