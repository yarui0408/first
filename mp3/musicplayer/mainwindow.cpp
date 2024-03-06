#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    this->setWindowIcon(QIcon(":/new/prefix1/images/logo.png"));


    //去掉窗口标题栏
    this->setWindowFlag(Qt::FramelessWindowHint);
    //禁止窗口改变尺寸大小
    this->setFixedSize(this->width(),this->height());
    //播放进度条控件美化
    ui->horizontalSlider_PlayProgress->setStyleSheet(
                "QSlider::groove:horizontal {"
                "border:1px solid skyblue;"
                "background-color:skyblue;"
                "height:10px;"
                "border-radius:5px;"
                "}"

                "QSlider::handle:horizontal {"
                "background:qradialgradient(spread:pad,cx:0.5,cy:0.5,radius:0.5,fx:0.5,fy:0.5,stop:0.7 white,stop:0.8 rgb(140,212,225));"
                "width:20px;"
                "border-radius:10px;"
                "margin-top:-5px;"
                "margin-bottom:-5px;}"

                "horizontalSlider::sub-page:horizontal{"
                "background:red;"
                "margin:5px;"
                "border-radius:5px;}"
                );

    ui->horizontalSlider_Volume->setStyleSheet(
                "QSlider::groove:horizontal {"
                "border:1px solid skyblue;"
                "background-color:skyblue;"
                "height:10px;"
                "border-radius:5px;"
                "}"

                "QSlider::handle:horizontal {"
                "background:qradialgradient(spread:pad,cx:0.5,cy:0.5,radius:0.5,fx:0.5,fy:0.5,stop:0.7 white,stop:0.8 rgb(140,212,225));"
                "width:20px;"
                "border-radius:10px;"
                "margin-top:-5px;"
                "margin-bottom:-5px;}"

                "horizontalSlider::sub-page:horizontal{"
                "background:red;"
                "margin:5px;"
                "border-radius:5px;}"
                );
    //将光标焦点定位到搜索歌曲名称控件当中
    ui->lineEdit_InputSongs->setFocus();

    //初始化QNetworkAccessManager一个实例
    NetworkAccessManagers=new QNetworkAccessManager(this);

    iPlayFlags=0;//标记播放状态为0

    //文本对象
    docTextObject=ui->plainTextEdit_SongList->document();
    //将控件设置为只读
    ui->plainTextEdit_SongList->setReadOnly(true);

    //初始化多媒体实例
    p_PlayerObject=new QMediaPlayer(this);
    p_PlayerList=new QMediaPlaylist(this);

    //设置播放列表
    p_PlayerObject->setMedia(p_PlayerList);
    //设置播放模式
    p_PlayerList->setPlaybackMode(QMediaPlaylist::Loop);

    //信号与槽处理
    connect(p_PlayerObject,SIGNAL(positionChanged(qint64)),this,SLOT(HandleLCDNumberTimeChangeFunc(qint64)));
    connect(p_PlayerObject,SIGNAL(positionChanged(qint64)),this,SLOT(HandlePositionChangeFunc(qint64)));
    connect(p_PlayerObject,SIGNAL(durationChanged(qint64)),this,SLOT(HandleProgressTimeChangeFunc(qint64)));

    connect(NetworkAccessManagers,SIGNAL(finished(QNetworkReply*)),this,SLOT(HandleDataBackFunc(QNetworkReply *)));

    //处理标题显示歌曲信息动画字幕
    ui->label_DisplaySongTitle->setFont(QFont("宋体",14,QFont::Normal));
    strTitles=ui->label_DisplaySongTitle->text();
    //使用计时器来移动标题
    QTimer *p_MoveTitle=new QTimer(this);
    iTitleChar=0;
    connect(p_MoveTitle,SIGNAL(timeout()),this,SLOT(titleMoveCaptionChar()));
    p_MoveTitle->start(1000);


    ui->pushButton_SearchSong->setStyleSheet("background-color:rgb(255,255,255,70);color: rgb(255, 255, 255);");
    ui->pushButton_St->setStyleSheet("background-color:rgb(255,255,255,70);color: rgb(255, 255, 255);");
    ui->lineEdit_InputSongs->setStyleSheet("background-color:rgb(255,255,255,70);color: rgb(255, 255, 255);");
    ui->label_DisplaySongTitle->setStyleSheet("background-color:rgb(255,255,255,70);color: rgb(255, 255, 255);");
    ui->plainTextEdit_SongList->setStyleSheet("background-color:rgb(255,255,255,70);color: rgb(255, 255, 255);");
    ui->lineEdit_InputSongs->setCursor(QCursor(Qt::PointingHandCursor));//鼠标经过该区域变手型


}

MainWindow::~MainWindow()
{
    delete ui;
}




void MainWindow::paintEvent(QPaintEvent *event)
{
    QPainter qPainter(this);
    //调用drawpixmap（）函数进行绘制
    qPainter.drawPixmap(0,0,width(),height(),QPixmap(":/new/prefix1/images/Mbg.jpg"));
}

//功能：使用鼠标拖动窗口移动MP3播放器到桌面的任意位置
void MainWindow::mousePressEvent(QMouseEvent *event)
{
    if(event->button()==Qt::LeftButton)
    {
        m_MouseDrag=true;
        mouseStartPoint=event->globalPos();
        windowStartPoint=this->frameGeometry().topLeft();
    }
}

void MainWindow::mouseMoveEvent(QMouseEvent *event)
{
    if(m_MouseDrag)
    {
        //获取鼠标移动的距离
        QPoint m_Distance=event->globalPos()-mouseStartPoint;
        //更改窗口对应位置
        this->move(windowStartPoint+m_Distance);
    }
}

 void MainWindow::mouseReleaseEvent(QMouseEvent *event)
 {
     //释放鼠标事件（左键）
     if(event->button()==Qt::LeftButton)
     {
         m_MouseDrag=false;
     }
 }

 void MainWindow::HandleDataBackFunc(QNetworkReply *pReply)
 {
     //读取网络回馈数据
     QByteArySearchInfo=pReply->readAll();

     QJsonParseError JSonPError;//定义错误信息对象

     //将json文本转换为json文件对象
    QJsonDocument JSonDoc_RecvData=QJsonDocument::fromJson(QByteArySearchInfo,&JSonPError);
    if(JSonPError.error!=QJsonParseError::NoError)//判断是否符合规则
    {
        QMessageBox::critical(this,"Prompt","提示：搜索歌词获取json格式错误，请重新检查",QMessageBox::Yes);
        return;
    }
    //Qjsonobject使用函数object（）
    QJsonObject TotalJsonObject=JSonDoc_RecvData.object();
    //列出json里面所有的key1
    QStringList strKeys=TotalJsonObject.keys();

    if(strKeys.contains("result"))//有数据信息
    {
        //将带有resoult的数据内容提取之后转换为对象
        QJsonObject resultobject=TotalJsonObject["result"].toObject();
         //存储所有keys
        QStringList strResultKeys=resultobject.keys();
        //如果keys是songs，证明搜索到对应的歌曲
        if(strResultKeys.contains("songs"))
        {
            QJsonArray array=resultobject["songs"].toArray();
            //通过for循环查找歌曲当中的字段信息
            for(auto isong:array)
            {
                QJsonObject jsonobject1=isong.toObject();

                //获取歌曲ID 歌名 歌手
                I_MusicID=jsonobject1["id"].toInt();
                StrMusicName=jsonobject1["name"].toString();

                QStringList strKeys=jsonobject1.keys();

                if(strKeys.contains("artists"))
                {
                    QJsonArray artistsjsonarray=jsonobject1["artists"].toArray();
                     for(auto js:artistsjsonarray)
                     {
                         QJsonObject jsonobject2=js.toObject();
                         StrSingerName=jsonobject2["name"].toString();
                     }
                }
            }
        }
    }
    QString strURL;
    strURL=QString("https://music.163.com/song/media/outer/url?id=%0").arg(I_MusicID);
                   //"https://music.163.com/song/media/outer/url?id=%0"
    p_PlayerList->addMedia(QUrl(strURL));
    ui->plainTextEdit_SongList->appendPlainText(StrMusicName+"-"+StrSingerName);
 }

 void MainWindow::HandleLCDNumberTimeChangeFunc(qint64 SongDuration)
 {
     int int_Second=SongDuration/1000;
     int int_Minute=int_Second/60;
     int_Second=int_Second%60;

     QString strSongTime=QString::asprintf("%d:%d",int_Minute,int_Second);
     ui->lcdNumber_PlayTime->display(strSongTime);

 }

 void MainWindow::HandleProgressTimeChangeFunc(qint64 SongDuration)
 {
     //设置进度条最大值
     ui->horizontalSlider_PlayProgress->setMaximum(SongDuration);

     int int_Value=p_PlayerList->currentIndex();

     QTextBlock qtextblocks=docTextObject->findBlockByLineNumber(int_Value);
     QString strTitle=qtextblocks.text();
     ui->label_DisplaySongTitle->setText(strTitle);
 }

void MainWindow::HandlePositionChangeFunc(qint64 position)
{
    if(ui->horizontalSlider_PlayProgress->isSliderDown())
        return;
    //设置滑块位置
    ui->horizontalSlider_PlayProgress->setSliderPosition(position);
}








void MainWindow::titleMoveCaptionChar()
{
    strTitles=ui->label_DisplaySongTitle->text();
    if(iTitleChar<strTitles.length())
    {
        QString strTemp=strTitles.mid(iTitleChar)+strTitles.mid(0,iTitleChar);
        ui->label_DisplaySongTitle->setText(strTemp);
        iTitleChar++;
    }
    else
        iTitleChar=0;
}

void MainWindow::on_pushButton_Exit_clicked()
{
    this->close();
}

void MainWindow::on_pushButton_About_clicked()
{
    AboutDialog *pAboutDialogs=new AboutDialog(this);
    QRect qRect=geometry();
    int iX=qRect.x()+144;
    int iY=qRect.y()+158;
    pAboutDialogs->setGeometry(iX,iY,643,486);//354 170

    //执行模态对话框
    pAboutDialogs->exec();
}

void MainWindow::on_pushButton_AddSong_clicked()
{
    QString strCurrentPaths=QDir::homePath();
    QString strDlgTitle="请选择MP3音乐文件";
    QString strFilters="所有文件（*.*）;;音频文件(*.mp3);;mp3文件(*.mp3)";

    QStringList strMp3FileList=QFileDialog::getOpenFileNames(this,strDlgTitle,strCurrentPaths,strFilters);

    if(strMp3FileList.count()<1)
        return;
    for(int i=0;i<strMp3FileList.count();i++)
    {
        QString strFiles=strMp3FileList.at(i);
        //将音乐文件添加播放列表
        p_PlayerList->addMedia(QUrl::fromLocalFile(strFiles));
        QFileInfo qFileInfo(strFiles);

        //将歌曲添加到plaintextedit控件
        ui->plainTextEdit_SongList->appendPlainText(qFileInfo.fileName());
    }
    //添加完毕立刻播放
    if(p_PlayerObject->state()!=QMediaPlayer::PlayingState)
        p_PlayerList->setCurrentIndex(0);
    p_PlayerObject->play();
}

void MainWindow::on_pushButton_PlaySong_clicked()
{
    //如果是停止状态或暂停状态，则播放
    if(iPlayFlags==0)
    {
        p_PlayerObject->play();
        iPlayFlags=1;
    }
    else if(p_PlayerList->currentIndex()<0)
    {
        p_PlayerList->setCurrentIndex(0);
    }
    p_PlayerObject->play();
}

void MainWindow::on_pushButton_PauseSong_clicked()
{
    //如果是播放状态，则暂定
    if(iPlayFlags==1)
    {
        p_PlayerObject->pause();
        iPlayFlags=0;
    }
}

void MainWindow::on_pushButton_StopPlaySong_clicked()
{
    p_PlayerObject->stop();
}

void MainWindow::on_pushButton_PreviousSong_clicked()
{
    int m_index=p_PlayerList->currentIndex();
    int m_indexsum=p_PlayerList->mediaCount();

    if(m_index>0)
    {
        m_index=m_index-1;
        p_PlayerList->setCurrentIndex(m_index);
        p_PlayerObject->play();
    }
    else
    {
        m_index=m_indexsum-1;
        p_PlayerList->setCurrentIndex(m_index);
        p_PlayerObject->play();
    }
}

void MainWindow::on_pushButton_PlayNextSong_clicked()
{
    int m_index=p_PlayerList->currentIndex();
    int m_indexsum=p_PlayerList->mediaCount();

    if(m_index<m_indexsum)
    {
        m_index=m_index+1;
        p_PlayerList->setCurrentIndex(m_index);
        p_PlayerObject->play();
    }
    else
    {
        m_index=0;
        p_PlayerList->setCurrentIndex(m_index);
        p_PlayerObject->play();
    }
}

void MainWindow::on_pushButton_SearchSong_clicked()
{
    QString str1,str2;
    str1=ui->lineEdit_InputSongs->text();
    str2="http://music.163.com/api/search/get/web?csrf_token=hlpretag=&hlposttag=&s={"+str1+"}&type=1&offset=0&total=true&limit=1";
  //str2="http://music.163.com/api/search/get/web?csrf_token=hlpretag=&hlposttag=&s={"+str1+"}&type=1&offset=0&total=true&limit=1";

    //定义一个qnetworkrequest请求对象
    QNetworkRequest networkRequest;
    //将请求格式设置给对应请求对象
    networkRequest.setUrl(str2);
    //使用qnetworkaccessmanager类对应的api发送get请求并获取响应数据
    NetworkAccessManagers->get(networkRequest);//请求处理
}

void MainWindow::on_pushButton_SoundYesNo_clicked()
{
    bool bMutexState=p_PlayerObject->isMuted();
    p_PlayerObject->setMuted(!bMutexState);

    if(bMutexState)
    {
        ui->pushButton_SoundYesNo->setIcon(QIcon(":/new/prefix1/images/MSound.png"));
    }
    else
    {
        ui->pushButton_SoundYesNo->setIcon(QIcon(":/new/prefix1/images/MNoSound.png"));
    }
}

void MainWindow::on_horizontalSlider_Volume_valueChanged(int value)
{
    p_PlayerObject->setVolume(value);
}

void MainWindow::on_horizontalSlider_PlayProgress_valueChanged(int value)
{
    p_PlayerObject->setPosition(value);
}
