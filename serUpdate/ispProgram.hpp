#pragma once
#include <QThread>
#include "serUpdate.h"
#include<windows.h>
#include <QSemaphore>
#include <QDebug>
extern QSemaphore ackGet;
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
    QByteArray HexStringToByteArray(QString hex)
    {
        int p;

        QByteArray ret;
        QStringList lst = hex.simplified().split(' ');//转化为字符串数组
        ret.resize(lst.count());
        for (int i = 0; i < lst.count(); i++)
        {
            p = lst[i].toInt(NULL, 16);
            ret[i] = p;
            qDebug() << ret[i] << endl;

        }
        
        return ret;
    }
private:
    QSerialPort* ispSerialName;
    QMutex* ispSerMutex;
    QByteArray binData;
    QString serText;
    void waitACK()
    {
        while(ackGet.available()>0)
        {
            Sleep(10);
        }
        ackGet.acquire();
    }
    QByteArray intToByte(int i)
    {
        QByteArray abyte0;
        abyte0.resize(1);
        abyte0[0] = (uchar)(0x000000ff & i);
        return abyte0;
    }

private slots:
    void run();

signals:
    void onNewSerialIspStatus(qint8, QString);
    void sendByte(QByteArray);
    void downLoadPercent(int);
};