#ifndef __SERIALPORTLIST_H
#define __SERIALPORTLIST_H

#include <QTimer>
#include <QDebug>
#include <QSerialPort>
#include <QStringList>
#include <QSerialPortInfo>
#define  DEBUG_INFOR_EN   0


class SerialPortList : public QObject
{
    Q_OBJECT

public:
    SerialPortList();
    SerialPortList(quint16);
    ~SerialPortList();

    quint16 scanCycleMs;
    QTimer *timer;
    QStringList oldPortStringList;

    void ScanStart();
    void ScanStop();

public slots:
    void onTimeOut();

signals:
    void onNewSerialPort(QStringList);
};

#endif // SERIALPORTLIST_H