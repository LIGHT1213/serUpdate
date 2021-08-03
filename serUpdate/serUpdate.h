#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_serUpdate.h"

#include "qserialport.h"
#include <qtextcodec.h> 
#include <QThread>
#include <QFileDialog>

#include <QMutex>
extern bool ackFlag;
extern QSerialPort* mySerial;
class serUpdate : public QMainWindow
{
    Q_OBJECT

public:
    serUpdate(QWidget *parent = Q_NULLPTR);
    bool ackFlag=false;
    QMutex* serMutex = new QMutex();
    
private:
    Ui::serUpdateClass ui;
    
    QTextCodec* codec = QTextCodec::codecForName("utf8");
    QString serRecData;
    void startSerialRec();
    QByteArray binData;
private slots:
    void UpdateSerPort(QStringList portName);
    void onSerConnnectPushButtom_callback();
    void onOpenFilePushButtom_callback();
    void onUploadPushButtom_callback();
    void UpdateSerialData(QString data);
    void processIspStatus(qint8, QString);
};
