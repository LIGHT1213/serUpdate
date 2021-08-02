#ifndef __SEREC_H
#define __SEREC_H
#include <QThread>
#include "serUpdate.h"
class serialRecThread:public QObject
{
    Q_OBJECT
    public:
        serialRecThread();
        serialRecThread(QSerialPort*);
        ~serialRecThread();
        void StartRec();
        
    private:
        QSerialPort* recSerialName;
    private slots:
        void run();
    signals:
        void onNewSerialString(QString);


};
#endif // !1
