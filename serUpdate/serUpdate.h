#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_serUpdate.h"

#include "qserialport.h"
#include <qtextcodec.h> 
#include <QThread>
#include <QFileDialog>
class serUpdate : public QMainWindow
{
    Q_OBJECT

public:
    serUpdate(QWidget *parent = Q_NULLPTR);

private:
    Ui::serUpdateClass ui;
    QSerialPort* mySerial = new QSerialPort();
    QTextCodec* codec = QTextCodec::codecForName("GBK");
    QString serRecData;
    void startSerialRec();
    QByteArray binData;
    typedef struct {
        char serModeSelect = '7f';
    }updateCommand;
    updateCommand myUpdateCommand;
    void waitForACK();
private slots:
    void UpdateSerPort(QStringList portName);
    void onSerConnnectPushButtom_callback();
    void onOpenFilePushButtom_callback();
    void onUploadPushButtom_callback();
    void UpdateSerialData(QString data);
    
};
