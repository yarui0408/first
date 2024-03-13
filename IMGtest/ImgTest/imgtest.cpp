#include "imgtest.h"
#include "ui_imgtest.h"
#include<QImage>
#include <QPainter>

ImgTest::ImgTest(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ImgTest)
{
    ui->setupUi(this);

    cameraInfoList= QCameraInfo::availableCameras();
    for(const QCameraInfo &tmpCam:cameraInfoList)
    {
        //qDebug()<<tmpCam.deviceName()<<"|||"<<tmpCam.description();
        ui->comboBox->addItem(tmpCam.description());

    }
    connect(ui->comboBox,QOverload<int>::of(&QComboBox::currentIndexChanged),this,&ImgTest::pickCamera);

    //设置照相头功能
    camera=new QCamera();
    finder=new QCameraViewfinder();
    imagecapture=new QCameraImageCapture(camera);
    camera->setViewfinder(finder);

    camera->setCaptureMode(QCamera::CaptureStillImage);
    imagecapture->setCaptureDestination(QCameraImageCapture::CaptureToBuffer);

    connect(imagecapture,&QCameraImageCapture::imageCaptured,this,&ImgTest::showCamera);
    //connect(ui->pushButton,&QPushButton::clicked,this,&ImgTest::prePostData);
    connect(ui->pushButton,&QPushButton::clicked,this,&ImgTest::beginGame);



    camera->start();


    gameCount=3;
    gameStr="猜拳游戏";
    ui->labelGame->setText(gameStr);
    //界面布局
    this->resize(975,642);
    QVBoxLayout *vboxl=new QVBoxLayout();
    //vboxl->addWidget(ui->label);
    vboxl->addWidget(ui->labelGame);
    vboxl->addWidget(ui->pushButton);
    vboxl->addWidget(ui->label);


    QVBoxLayout *vboxr=new QVBoxLayout();
    vboxr->addWidget(ui->comboBox);
    vboxr->addWidget(finder);
    vboxr->addWidget(ui->textBrowser);

    QHBoxLayout *hbox=new QHBoxLayout(this);
    hbox->addLayout(vboxl);
    hbox->addLayout(vboxr);
    this->setLayout(hbox);

    //利用定时器不断刷新拍照界面
    refreshTimer=new QTimer(this);
    connect(refreshTimer,&QTimer::timeout,this,&ImgTest::takePicture);
    refreshTimer->start(10);

    //利用定时器不断进行人脸识别请求
    netTimer=new QTimer(this);
    connect(netTimer,&QTimer::timeout,this,&ImgTest::prePostData);

    //游戏倒计时
    gameTimer=new QTimer(this);
    connect(gameTimer,&QTimer::timeout,this,&ImgTest::analysGame);

    tokenManager=new QNetworkAccessManager(this);
    connect(tokenManager,&QNetworkAccessManager::finished,this,&ImgTest::tokenReply);

    imgManager=new QNetworkAccessManager(this);
    connect(imgManager,&QNetworkAccessManager::finished,this,&ImgTest::imgReply);

    qDebug()<<tokenManager->supportedSchemes();

    QUrl url("https://aip.baidubce.com/oauth/2.0/token");
    qDebug()<<url;

    QUrlQuery query;
    //query.addQueryItem("grant_type","client_credentials");
    //query.addQueryItem("client_id","mb07iptJOf2jm3ThV9x6lcmP");
    //query.addQueryItem("client_secret","PIOAlldHkuz2XiIpftL8U5oTb8q3lzIJ");

    //手势识别
    query.addQueryItem("grant_type","client_credentials");
    query.addQueryItem("client_id","UMSrdrYo8ZC3uaDipuwh3ffO");
    query.addQueryItem("client_secret","njFfU0fh4rWArkfaKD9DaES8LLCPZbmH");



    url.setQuery(query);
    qDebug()<<url;

    //ssl支持
    if(QSslSocket::supportsSsl())
    {
       qDebug()<<"支持ssl";
    }
    else
    {
      qDebug()<<"不支持ssl";
    }

    sslConfig=QSslConfiguration::defaultConfiguration();
    sslConfig.setPeerVerifyMode(QSslSocket::QueryPeer);
    sslConfig.setProtocol(QSsl::TlsV1_2);





    //组装发送请求
    QNetworkRequest req;
    req.setUrl(url);
    req.setSslConfiguration(sslConfig);

    tokenManager->get(req);



    //qDebug() << QSslSocket::sslLibraryBuildVersionString();


}
void ImgTest::showCamera(int id,QImage img)
{
    Q_UNUSED(id);

    this->img=img;

    //绘制人脸框
//    QPainter p(&img);
//    p.setPen(Qt::black);
//    p.drawRect(faceleft,facetop,facewidth,faceheight);

//    QFont font=p.font();
//    font.setPixelSize(30);
//    p.setFont(font);

//    p.drawText(faceleft+facewidth+5,facetop,QString("age").append(QString::number(age)));
//    p.drawText(faceleft+facewidth+5,facetop+40,QString("gender").append(gender));
//    p.drawText(faceleft+facewidth+5,facetop+80,QString("mask").append(mask==0?"未检测到口罩":"检测到已戴口罩"));
//    p.drawText(faceleft+facewidth+5,facetop+120,QString("beauty").append(QString::number(beauty)));

    ui->label->setPixmap(QPixmap::fromImage(img));
}
void ImgTest::takePicture()
{
    imagecapture->capture();
}
void ImgTest::tokenReply(QNetworkReply *reply)
{
    //错误处理
    if(reply->error()!=QNetworkReply::NoError)
    {
        qDebug()<<reply->errorString();
        return;
    }

    //正常应答
    const QByteArray reply_data=reply->readAll();

    //qDebug()<<reply_data;

    //json解析

    QJsonParseError jsonErr;
    QJsonDocument doc=QJsonDocument::fromJson(reply_data,&jsonErr);

    if(jsonErr.error==QJsonParseError::NoError)
    {
        //解析成功
        QJsonObject obj=doc.object();
        if(obj.contains("access_token"))
        {
            accessToken=obj.take("access_token").toString();
        }

        ui->textBrowser->setText(accessToken);
    }
    else
    {
        qDebug()<<"json error"<<jsonErr.errorString();
    }
    reply->deleteLater();

    //prePostData();
    //netTimer->start(1500);


}

void ImgTest::prePostData()
{
    //创建子线程
    //创建工人
    //把工人送进子线程
    //绑定信号与槽的关系
    //启动子线程
    //给工人发通知干活
    childThread=new QThread(this);
    Worker *worker=new Worker;
    worker->moveToThread(childThread);
    connect(this,&ImgTest::beginWork,worker,&Worker::doWork);
    connect(worker,&Worker::resultReady,this,&ImgTest::beginFaceDetect);
    connect(childThread,&QThread::finished,worker,&QObject::deleteLater);

    childThread->start();
    emit beginWork(img,childThread);
}
void ImgTest::beginFaceDetect(QByteArray postData,QThread *overThread)
{

    //另一个槽内容
    //关闭子线程
    //用post发送数据给百度api

    overThread->exit();
    overThread->wait();

    if(childThread->isFinished())
    {
        qDebug()<<"子线程结束了";
    }
    else
    {
        qDebug()<<"子线程未结束";
    }


    //组装图像识别请求
    //QUrl url("https://aip.baidubce.com/rest/2.0/face/v3/detect");
    QUrl url("https://aip.baidubce.com/rest/2.0/image-classify/v1/gesture");



    QUrlQuery query;
    query.addQueryItem("access_token",accessToken);
    url.setQuery(query);

    QNetworkRequest req;
    //req.setHeader(QNetworkRequest::ContentTypeHeader,QVariant("application/json"));
    req.setHeader(QNetworkRequest::ContentTypeHeader,QVariant("application/x-www-form-urlencoded"));

    req.setUrl(url);
    req.setSslConfiguration(sslConfig);

    qDebug()<<"run 2";

    imgManager->post(req,postData);

    qDebug()<<"over";
}
void ImgTest::imgReply(QNetworkReply *reply)
{
    if(reply->error()!=QNetworkReply::NoError)
    {
        qDebug()<<reply->errorString();
        return;
    }
    const QByteArray reply_data=reply->readAll();
    //qDebug()<<reply_data;

    QJsonParseError jsonErr;
    QJsonDocument doc=QJsonDocument::fromJson(reply_data,&jsonErr);
    if(jsonErr.error==QJsonParseError::NoError)
    {
        QString faceInfo;
        //取出最外层json
        QJsonObject obj=doc.object();
            //**************手势识别结果分析**********************
        yourHand=-1;
        if(obj.contains("result_num"))
        {
            int result_num=obj.take("result_num").toInt();
            if(obj.contains("result"))
            {
                QJsonArray resultArr=obj.take("result").toArray();

                for(int i=0;i<result_num;i++)
                {
                    QJsonObject handObj=resultArr.at(i).toObject();
                    if(handObj.contains("classname"))
                    {
                        QString handClass=handObj.take("classname").toString();
                        faceInfo.append(QString::number(i+1)).append(".").append(handClass).append("\r\n");

                        if(handClass=="Fist")
                        {
                            yourHand=0;
                            break;
                        }
                        else if(handClass=="Two")
                        {
                            yourHand=1;
                            break;
                        }
                        else if(handClass=="Five")
                        {
                            yourHand=2;
                            break;
                        }

                    }
                }
                if(yourHand<0)
                {
                    gameStr="识别失败请重试";
                    ui->labelGame->setText(gameStr);
                }
                else
                {
                    int res=(yourHand+3-computerHand)%3;
                    gameStr.clear();
                    gameStr.append("出拳！！！电脑出拳：")
                           .append(computerHand==0?"石头":(computerHand==1?"剪刀":"布"))
                           .append(",你的出拳：")
                           .append(yourHand==0?"石头":(yourHand==1?"剪刀":"布"))
                            .append("，结果：")
                            .append(res==0?"平局":(computerHand==1?"你输了":"你赢了"));
                    ui->labelGame->setText(gameStr);
                }
            }

        }
        ui->textBrowser->setText(faceInfo);








            //***************人脸识别结果分析**********************
//        if(obj.contains("timestamp"))
//        {
//            int tmpTime=obj.take("timestamp").toInt();
//            if(tmpTime<latestTime)
//            {
//                return;
//            }
//            else
//            {
//                latestTime=tmpTime;
//            }
//        }


//        if(obj.contains("result"))
//        {

//            QJsonObject resultObj=obj.take("result").toObject();


//            //取出人脸列表
//            if(resultObj.contains("face_list"))
//            {
//                QJsonArray face_list=resultObj.take("face_list").toArray();
//                //取出第一张人脸信息
//                QJsonObject faceObject=face_list.at(0).toObject();

//                //取出location人脸定位信息
//                if(faceObject.contains("location"))
//                {
//                    QJsonObject locationObj=faceObject.take("location").toObject();
//                    if(locationObj.contains("left"))
//                    {
//                        faceleft=locationObj.take("left").toDouble();
//                    }
//                    if(locationObj.contains("top"))
//                    {
//                        facetop=locationObj.take("top").toDouble();
//                    }
//                    if(locationObj.contains("width"))
//                    {
//                        facewidth=locationObj.take("width").toDouble();
//                    }
//                    if(locationObj.contains("height"))
//                    {
//                        faceheight=locationObj.take("height").toDouble();
//                    }

//                }

//                //取出年龄
//                if(faceObject.contains("age"))
//                {
//                    age=faceObject.take("age").toDouble();
//                    faceInfo.append("age:").append(QString::number(age)).append("\r\n");
//                }
//                if(faceObject.contains("gender"))
//                {
//                    QJsonObject genderObj=faceObject.take("gender").toObject();
//                    if(genderObj.contains("type"))
//                    {
//                        gender=genderObj.take("type").toString();
//                    faceInfo.append("gender:").append(gender).append("\r\n");
//                    }

//                }
//                if(faceObject.contains("emotion"))
//                {
//                    QJsonObject emotionObj=faceObject.take("emotion").toObject();
//                    if(emotionObj.contains("type"))
//                    {
//                        QString emotion=emotionObj.take("type").toString();
//                    faceInfo.append("emotion:").append(emotion).append("\r\n");
//                    }

//                }
//                if(faceObject.contains("mask"))
//                {
//                    QJsonObject maskObj=faceObject.take("mask").toObject();
//                    if(maskObj.contains("type"))
//                    {
//                        mask=maskObj.take("type").toInt();
//                    faceInfo.append("mask:").append(mask==0?"未检测到口罩":"检测到已戴口罩").append("\r\n");
//                    }

//                }
//                if(faceObject.contains("beauty"))
//                {
//                    beauty=faceObject.take("beauty").toDouble();
//                    faceInfo.append("beauty:").append(QString::number(beauty)).append("\r\n");
//                }
//            }
//        }
//      ui->textBrowser->setText(faceInfo);
    }
    else
    {
        qDebug()<<"json error:"<<jsonErr.errorString();
    }
    reply->deleteLater();

    //prePostData();
}
ImgTest::~ImgTest()
{
    delete ui;
}

void ImgTest::pickCamera(int idx)
{
    qDebug()<<cameraInfoList.at(idx).description();

    refreshTimer->stop();
    camera->stop();

    camera=new QCamera(cameraInfoList.at(idx));
    imagecapture=new QCameraImageCapture(camera);

    connect(imagecapture,&QCameraImageCapture::imageCaptured,this,&ImgTest::showCamera);

    imagecapture->setCaptureDestination(QCameraImageCapture::CaptureToBuffer);
    camera->setCaptureMode(QCamera::CaptureStillImage);

    camera->setViewfinder(finder);
    camera->start();
    refreshTimer->start(10);
}

void ImgTest::beginGame()
{
    ui->pushButton->setEnabled(false);
    gameStr="准备出拳"+QString::number(gameCount);
    ui->labelGame->setText(gameStr);
    gameTimer->start(1000);
}
void ImgTest::analysGame()
{
    if(--gameCount>0)
    {
        gameStr="准备出拳"+QString::number(gameCount);
        ui->labelGame->setText(gameStr);
    }
    else
    {
        computerHand=QRandomGenerator::global()->generate()%3;
        gameTimer->stop();
        ui->pushButton->setEnabled(true);
        gameCount=3;
        gameStr.clear();
        gameStr.append("出拳！！！电脑出拳：")
               .append(computerHand==0?"石头":(computerHand==1?"剪刀":"布"))
                .append("你的出拳：分析中").append(yourHand);
        ui->labelGame->setText(gameStr);
        prePostData();

    }
}
