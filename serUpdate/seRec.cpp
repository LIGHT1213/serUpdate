#include "seRec.hpp"
serialRecThread::serialRecThread()
{
    //recSerialName=MainWindow::GetSerial();
}
serialRecThread::serialRecThread(QSerialPort* Serial, QMutex* serMutex)
{
    recSerialName=Serial;
    serStringMutex = serMutex;
}
serialRecThread::~serialRecThread()
{
    delete recSerialName;
}
void serialRecThread::run()
{
    //read()
    this->serStringMutex->lock();
    QByteArray RecData;
    QString RecSting;
    qint64 byteNum=0;
    if(recSerialName->isOpen())
    {
        byteNum=recSerialName->bytesAvailable();
        if(byteNum)
        {
            RecData=recSerialName->readAll();
            RecSting=QString(RecData);
            emit onNewSerialString(RecSting);

        }
    }
    this->serStringMutex->unlock();
}
