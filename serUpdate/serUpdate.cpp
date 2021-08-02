#include "serUpdate.h"
#include "serPortList.hpp"
#include "seRec.hpp"
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
        mySerial->setParity(QSerialPort::NoParity);
        mySerial->setStopBits(QSerialPort::OneStop);
        mySerial->setDataBits(QSerialPort::Data8);
        if (mySerial->open(QIODevice::ReadWrite))
        {
            //ui->serStates->setText("Serial is open");
            ui.downloadStatus->setText(this->codec->toUnicode("����������"));
            //ui->OpenSerial->setCheckable(false);
            ui.serConnect->setText(this->codec->toUnicode("�Ͽ�����"));
            connectFlag = true;
        }
        else
        {
            ui.downloadStatus->setText(this->codec->toUnicode("��������ʧ��"));
        }
    }
    else
    {
        mySerial->close();
        ui.downloadStatus->setText(this->codec->toUnicode("�����ѶϿ�"));
        ui.serConnect->setText(this->codec->toUnicode("���Ӵ���"));
        connectFlag = false;
    }
}
// why to do this?
/*
 * After qt4.4 ,by this why to use thread ,and it was though true way,and what the qt want our do?
 * ps:���������������Ĺ���Ӣ������˼����qt�ٷ��������źźͲۺ������ñ�ֱ�Ӽ̳�thread����������,�Ҳ����qt�ٷ��˾ٵ�ԭ�򣬵����������һ���̶�����������Դʹ����
*/
void serUpdate::startSerialRec()
{
    serialRecThread* updateSerial = new serialRecThread(mySerial);
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
    this->serRecData = data;
}
void serUpdate::onOpenFilePushButtom_callback()
{

    QString fileName = QFileDialog::getOpenFileName(this, QString::fromLocal8Bit("bin file"), qApp->applicationDirPath(),
        QString::fromLocal8Bit("bin File(*.bin)"));//�½��ļ��򿪴���
    if (fileName.isEmpty())//���δѡ���ļ���ȷ�ϣ�������
        return;
    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly))
        ui.fileRoute->setText(file.errorString());//�ļ��򿪴�����ʾ������Ϣ
    else {
        binData = file.readAll();//��ȡ�ļ�
        ui.fileRoute->setText(fileName);
    }
    file.close();
}
void serUpdate::onUploadPushButtom_callback()
{
    QThread* ispThread = new QThread();
    QTimer* ispTimer = new QTimer(this);
    ispTimer->start(20);


    mySerial->close();
    mySerial->setPortName(ui.serList->currentText());
    mySerial->setBaudRate(QSerialPort::Baud115200);
    mySerial->setParity(QSerialPort::EvenParity);
    mySerial->setStopBits(QSerialPort::OneStop);
    mySerial->setDataBits(QSerialPort::Data8);
    try {
        mySerial->open(QIODevice::ReadWrite);
    }
    catch (...)
    {
        ui.downloadStatus->setText(this->codec->toUnicode("bootloaderͨѶʧ��"));
    }
    mySerial->write(QByteArray::fromHex(&myUpdateCommand.serModeSelect));
    waitForACK();

}
void serUpdate::waitForACK()
{
    if(this->serRecData==)
}

