#ifndef __SEREC_H
#define __SEREC_H
#include <QThread>
#include "serUpdate.h"
class serialRecThread:public QObject
{
    Q_OBJECT
    public:
        serialRecThread();
        serialRecThread(QSerialPort*, QMutex*);
        ~serialRecThread();
        
    private:
        QSerialPort* recSerialName;
        QMutex* serStringMutex;
    private slots:
        void run();
    signals:
        void onNewSerialString(QString);


};
#endif // !1
