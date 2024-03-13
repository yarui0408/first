#ifndef WORKER_H
#define WORKER_H

#include <QObject>


#include<QImage>
#include<QJsonObject>
#include<QJsonDocument>
#include<QBuffer>
#include<QString>
#include<QByteArray>
#include<QDebug>
//#include<QThread>
class Worker : public QObject
{
    Q_OBJECT
public:
    explicit Worker(QObject *parent = nullptr);
public slots:
    void doWork(QImage img,QThread *childThread);
signals:
    void resultReady(QByteArray pd,QThread *childThread);


};

#endif // WORKER_H
