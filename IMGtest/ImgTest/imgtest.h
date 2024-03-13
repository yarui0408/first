#ifndef IMGTEST_H
#define IMGTEST_H

#include <QWidget>
#include<QCamera>
#include<QCameraViewfinder>
#include<QCameraImageCapture>
#include<QNetworkAccessManager>
#include<QHBoxLayout>
#include<QVBoxLayout>
#include<QTimer>
#include<QUrlQuery>
#include<QUrl>
#include<QSslSocket>
#include<QSslConfiguration>
#include<QNetworkRequest>
#include<QNetworkReply>
#include<QJsonParseError>
#include<QJsonDocument>
#include<QJsonObject>
#include<QString>
#include<QBuffer>
#include<QJsonArray>
#include<QThread>
#include<QImage>
#include"worker.h"
#include<QObject>
#include<QPainter>
#include<QCameraInfo>
#include<QComboBox>
#include<QRandomGenerator>
QT_BEGIN_NAMESPACE
namespace Ui { class ImgTest; }
QT_END_NAMESPACE

class ImgTest : public QWidget
{
    Q_OBJECT
signals:
    void beginWork(QImage img,QThread *childThread);


public:
    ImgTest(QWidget *parent = nullptr);
    ~ImgTest();

public slots:
    void showCamera(int id,const QImage preview);
    void takePicture();
    void tokenReply(QNetworkReply *reply);
    void imgReply(QNetworkReply *reply);
    void beginFaceDetect(QByteArray postData,QThread *overThread);

    void prePostData();

    void pickCamera(int idx);

    void beginGame();
    void analysGame();
private:
    Ui::ImgTest *ui;



    QCamera *camera;
    QCameraViewfinder *finder;
    QCameraImageCapture *imagecapture;
    QTimer *refreshTimer;
    QTimer *netTimer;
    QNetworkAccessManager *tokenManager;
     QNetworkAccessManager *imgManager;
    QSslConfiguration sslConfig;
    QString accessToken;
    QImage img;
    QThread *childThread;


    double facetop;
    double faceleft;
    double facewidth;
    double faceheight;

    double age;
    QString gender;
    int mask;
    double beauty;

    int latestTime;

    QList<QCameraInfo> cameraInfoList;


    QString gameStr;
    int gameCount;
    QTimer *gameTimer;
    int computerHand;
    int yourHand;
};
#endif // IMGTEST_H
