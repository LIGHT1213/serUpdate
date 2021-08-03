#pragma execution_character_set("utf-8")   
#include "ispProgram.hpp"
void ispProgramThread::run()
{
    QByteArray command;
    this->ispSerMutex->lock();
    //try
    //{
    //    this->ispSerialName->close();
    //}
    //catch (...)
    //{
    //    emit onNewSerialIspStatus(0, QString("Bootload通讯建立失败"));
    //    return;
    //}
    //    emit onNewSerialIspStatus(0, QString("Bootload通讯建立成功"));
    //this->ispSerialName->setPortName(this->serText);
    //this->ispSerialName->setBaudRate(QSerialPort::Baud115200);
    //this->ispSerialName->setParity(QSerialPort::EvenParity);
    //this->ispSerialName->setStopBits(QSerialPort::OneStop);
    //this->ispSerialName->setDataBits(QSerialPort::Data8);
    //try 
    //{
    //    this->ispSerialName->open(QIODevice::ReadWrite);
    //}
    //catch (...)
    //{
    //    emit onNewSerialIspStatus(0, QString("Bootload进入串口模式失败"));
    //    return;
    //}
    this->ispSerMutex->unlock();
    command[0] = 0x7f;
    mySerial->write(command);
    waitACK();
    emit onNewSerialIspStatus(0, QString("Bootload进入串口模式成功"));
    command.resize(2);
    command[0] = 0x00; command[1] = 0xff;
    sendChar(command);
    waitACK();
    command[0] = 0x02; command[1] = 0xfd;
    sendChar(command);
    waitACK();
    emit onNewSerialIspStatus(0, QString("开始擦除FLASH"));
    command[0] = 0x02; command[1] = 0xfd;

}
void ispProgramThread::sendChar(QString data)
{
    this->ispSerMutex->lock();
    QByteArray send;
    QString sendRaw;
    sendRaw = data;
    send = sendRaw.toLocal8Bit();
    this->ispSerialName->write(send);
    this->ispSerMutex->unlock();
}
void ispProgramThread::sendChar(QByteArray data)
{
    this->ispSerMutex->lock();
    //ispSerialName->write(data);
    mySerial->write(data);
    this->ispSerMutex->unlock();
}
