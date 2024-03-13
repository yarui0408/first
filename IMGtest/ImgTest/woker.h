#ifndef WOKER_H
#define WOKER_H



#include<QObject>
#include<QImage>
#include<QJsonObject>
#include<QJsonDocument>
#include<QBuffer>
#include<QString>
#include<QByteArray>



class Woker : public QObject
{
    Q_OBJECT
public:
    explicit Woker(QObject *parent = nullptr);
public slots:
    void doWork();
signals:
    void resultReady(QByteArray pd);
};

#endif // WOKER_H
