#pragma execution_character_set("utf-8")  
#include "serUpdate.h"
#include "serPortList.hpp"
#include "seRec.hpp"
#include "ispProgram.hpp"
bool ackFlag = false;
QSerialPort* mySerial = new QSerialPort();
serUpdate::serUpdate(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    
    SerialPortList* portList = new SerialPortList(2000);
    portList->ScanStart();
    startSerialRec();
    QObject::connect(portList, SIGNAL(onNewSerialPort(QStringList)), this, SLOT(UpdateSerPort(QStringList)));
    QObject::connect(ui.serConnect, SIGNAL(clicked()), this, SLOT(onSerConnnectPushButtom_callback()));
    QObject::connect(ui.openFile, SIGNAL(clicked()), this, SLOT(onOpenFilePushButtom_callback()));
    QObject::connect(ui.upLoad, SIGNAL(clicked()), this, SLOT(onUploadPushButtom_callback()));
}
void serUpdate::UpdateSerPort(QStringList portName)
{
    ui.serList->clear();
    ui.serList->addItems(portName);
}
void serUpdate::onSerConnnectPushButtom_callback(void)
{
    static bool connectFlag=false;
    if (connectFlag == false)
    {
        mySerial->setPortName(ui.serList->currentText());
        mySerial->setBaudRate(QSerialPort::Baud115200);
        mySerial->setParity(QSerialPort::EvenParity);
        mySerial->setStopBits(QSerialPort::OneStop);
        mySerial->setDataBits(QSerialPort::Data8);
        if (mySerial->open(QIODevice::ReadWrite))
        {
            //ui->serStates->setText("Serial is open");
            ui.downloadStatus->setText(this->codec->toUnicode("串口已连接"));
            //ui->OpenSerial->setCheckable(false);
            ui.serConnect->setText(this->codec->toUnicode("断开连接"));
            connectFlag = true;
        }
        else
        {
            ui.downloadStatus->setText(this->codec->toUnicode("串口连接失败"));
        }
    }
    else
    {
        mySerial->close();
        ui.downloadStatus->setText(this->codec->toUnicode("串口已断开"));
        ui.serConnect->setText(this->codec->toUnicode("连接串口"));
        connectFlag = false;
    }
}
// why to do this?
/*
 * After qt4.4 ,by this why to use thread ,and it was though true way,and what the qt want our do?
 * ps:如果看不懂我上面的工地英语，大概意思就是qt官方觉得用信号和槽函数调用比直接继承thread类厉害多了,我不清楚qt官方此举的原因，但是这个操作一定程度上增加了资源使用量
*/
void serUpdate::startSerialRec()
{
    serialRecThread* updateSerial = new serialRecThread(mySerial,this->serMutex);
    //new a thread
    QThread* UpdateSer = new QThread();
    //a timer 
    QTimer* UpdateSerTimer = new QTimer(this);
    UpdateSerTimer->start(50);
    QObject::connect(UpdateSerTimer, SIGNAL(timeout()), updateSerial, SLOT(run()));
    updateSerial->moveToThread(UpdateSer);
    UpdateSer->start();
    QObject::connect(updateSerial, SIGNAL(onNewSerialString(QString)), this, SLOT(UpdateSerialData(QString)));
}
void serUpdate::UpdateSerialData(QString data)
{
    QString ackChar = 0x7f;
    this->serRecData = data;
    if (this->serRecData[0] == ackChar)
    {
        ackFlag = true;
    }
}
void serUpdate::onOpenFilePushButtom_callback()
{

    QString fileName = QFileDialog::getOpenFileName(this, QString::fromLocal8Bit("bin file"), qApp->applicationDirPath(),
        QString::fromLocal8Bit("bin File(*.bin)"));//新建文件打开窗口
    if (fileName.isEmpty())//如果未选择文件便确认，即返回
        return;
    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly))
        ui.fileRoute->setText(file.errorString());//文件打开错误显示错误信息
    else {
        binData = file.readAll();//读取文件
        ui.fileRoute->setText(fileName);
    }
    file.close();
}
void serUpdate::onUploadPushButtom_callback()
{
    ispProgramThread* ispSer = new ispProgramThread(mySerial,binData, ui.serList->currentText(), this->serMutex);
    QThread* ispThread = new QThread();
    QTimer* ispTimer = new QTimer(this);
    ispTimer->start(20);
    QObject::connect(ispTimer, SIGNAL(timeout()), ispSer, SLOT(run()));
    ispSer->moveToThread(ispThread);
    ispThread->start();
    QObject::connect(ispSer, SIGNAL(onNewSerialIspStatus(qint8, QString)), this, SLOT(processIspStatus(qint8, QString)));
}
void serUpdate::processIspStatus(qint8 processClass, QString data)
{
    QByteArray Temp;
    switch (processClass)
    {
    case 0:
    {
        Temp = data.toUtf8();
        ui.downloadStatus->setText(this->codec->toUnicode(Temp));
        break;
    }
    case 1:
    {
        break;
    }
    default:
        break;
    }
}
