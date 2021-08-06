#pragma execution_character_set("utf-8")   
#include "ispProgram.hpp"

void ispProgramThread::run()
{
    QByteArray command, addTemp, sendAddress, sendCheck;
    QString sumTemp;
    command[0] = 0x7f;
    emit sendByte(command);
    waitACK();
    emit onNewSerialIspStatus(0, QString("Bootload进入串口模式成功"));
    command.resize(2);
    command[0] = 0x00; command[1] = 0xff;
    emit sendByte(command);
    waitACK();
    command[0] = 0x02; command[1] = 0xfd;
    emit sendByte(command);
    waitACK();
    emit onNewSerialIspStatus(0, QString("开始擦除FLASH"));
    command[0] = 0x44; command[1] = 0xbb;
    emit sendByte(command);
    waitACK();
    command.resize(3);
    command[0] = 0xff; command[1] = 0xff; command[2] = 0x00;
    emit sendByte(command);
    waitACK();
    emit onNewSerialIspStatus(0, QString("FLASH擦除完毕"));
    addTemp[0] = 0xff;
    while (binData.length() % 256 != 0)
    {
        binData.append(addTemp);
    }
    emit onNewSerialIspStatus(0, QString("bin文件读入并处理完毕"));
    QString appAddressString = "8000000";
    for (int i = 0; i <= binData.length() / 256; i++)
    {
        command.resize(2);
        command[0] = 0x31; command[1] = 0xce;
        emit sendByte(command);
        waitACK();
        qDebug() << "31,ce"<<endl;
        quint8 appAddress[4], sumCheck;
        appAddress[0] = appAddressString.mid(0, 1).toInt(NULL,16);appAddress[1] = appAddressString.mid(1, 2).toInt(NULL, 16);
        appAddress[2] = appAddressString.mid(3, 2).toInt(NULL, 16);appAddress[3] = appAddressString.mid(5, 2).toInt(NULL, 16);
        
        sumCheck = appAddress[0] ^ appAddress[1] ^ appAddress[2] ^ appAddress[3];
        sendAddress.clear();
        for (int j = 0; j < 4; j++)
        {
            sendAddress.append(QByteArray::number(appAddress[j]));
        }
        sendCheck = QByteArray::number(sumCheck);
        emit sendByte(sendAddress);
        emit sendByte(sendCheck);
        waitACK();
        qDebug() << "address"<<endl;
        appAddressString=QString::number(appAddressString.toInt(NULL, 16)+0X100);
        QByteArray curWriteData = binData.mid(i * 256, i * 256 + 256);
        sumCheck = 0;
        for (int j = 0; j < 256; j++)
        {
            sumCheck ^= curWriteData[j];
        }
        sumCheck ^= 0xff;
        sendCheck = QByteArray::number(sumCheck);
        emit sendByte(QByteArray::number(255));
        emit sendByte(curWriteData);
        emit sendByte(sendCheck);
        waitACK();
        qDebug() << "DATA" << endl;
        emit downLoadPercent(i);
    }
}
