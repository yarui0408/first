#include "woker.h"

Woker::Woker(QObject *parent) : QObject(parent)
{

}
void Woker::doWork(QImage img)
{
    qDebug()<<"begin";
    //转成base64编码
    QByteArray ba;
    QBuffer buff(&ba);
    img.save(&buff,"png");
     qDebug()<<ba;
    QString b64str=ba.toBase64();
    qDebug()<<b64str;

    //请求体body参数设置
    QJsonObject postJson;
    QJsonDocument doc;

    postJson.insert("image",b64str);
    postJson.insert("image_type","BASE64");
    postJson.insert("face_field","age,expression,face_shape,gender,glasses,landmark,landmark150,quality,eye_status,emotion,face_type,mask,spoofing,beauty");


    doc.setObject(postJson);
    QByteArray postData=doc.toJson(QJsonDocument::Compact);

    emit resultReady(postData);
}
