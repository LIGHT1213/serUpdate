#include "seRec.hpp"
serialRecThread::serialRecThread()
{
    //recSerialName=MainWindow::GetSerial();
}
serialRecThread::serialRecThread(QSerialPort* Serial)
{
    recSerialName=Serial;
}
serialRecThread::~serialRecThread()
{
    delete recSerialName;
}
void serialRecThread::run()
{
    //read()
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
    //QThread::msleep(10);

}
