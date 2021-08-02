﻿#include "serPortList.hpp"
//默认构造函数
SerialPortList::SerialPortList()
{
    timer = new QTimer;
    scanCycleMs = 200;
    oldPortStringList.clear();
    connect(timer, SIGNAL(timeout()), this, SLOT(onTimeOut()));
}
//带参数的构造函数
SerialPortList::SerialPortList(quint16 CycleMs)
{
    timer = new QTimer;
    scanCycleMs = CycleMs;
    oldPortStringList.clear();
    connect(timer, SIGNAL(timeout()), this, SLOT(onTimeOut()));
}
//析构函数
SerialPortList::~SerialPortList()
{
    delete timer;
}
void SerialPortList::ScanStart()
{
    timer->stop();
    timer->start(scanCycleMs);
}
//停止扫描
void SerialPortList::ScanStop()
{
    timer->stop();
}

//周期扫描服务
void SerialPortList::onTimeOut()
{

    QStringList newPortStringList;
    //搜索串口
    foreach(const QSerialPortInfo & info, QSerialPortInfo::availablePorts())
    {
#if DEBUG_INFOR_EN
        qDebug() << "Name        : " << info.portName();
        qDebug() << "Description : " << info.description();
        qDebug() << "Manufacturer: " << info.manufacturer();
#endif
        newPortStringList += info.portName();
    }

    //更新旧的串口列表
    if (newPortStringList.size() != oldPortStringList.size())
    {
        oldPortStringList = newPortStringList;
        emit onNewSerialPort(oldPortStringList);
    }
}