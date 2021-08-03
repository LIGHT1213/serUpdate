#pragma once
#include <QThread>
#include "serUpdate.h"
#include<windows.h>
class ispProgramThread :public QObject
{
	Q_OBJECT
public:
    ispProgramThread(QSerialPort* Serial,QByteArray bin,QString comName, QMutex* ispMutex)
    {
        ispSerialName = Serial;
        binData = bin;
        serText = comName;
        ispSerMutex = ispMutex;
    }
    ~ispProgramThread()
    {
        delete ispSerialName;
    }

private:
    QSerialPort* ispSerialName;
    QMutex* ispSerMutex;
    QByteArray binData;
    QString serText;
    void sendChar(QString);
    void sendChar(QByteArray);
    void waitACK()
    {
        while(ackFlag == false)
        {
            Sleep(10);
        }
        ackFlag = false;
    }
private slots:
    void run();
signals:
    void onNewSerialIspStatus(qint8, QString);
};