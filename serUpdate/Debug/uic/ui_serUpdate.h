/********************************************************************************
** Form generated from reading UI file 'serUpdate.ui'
**
** Created by: Qt User Interface Compiler version 5.12.11
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SERUPDATE_H
#define UI_SERUPDATE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_serUpdateClass
{
public:
    QWidget *centralWidget;
    QLabel *label;
    QComboBox *serList;
    QPushButton *serConnect;
    QPushButton *openFile;
    QLabel *bootloadVer;
    QLabel *deviceID;
    QLabel *downloadStatus;
    QProgressBar *downloadProgress;
    QPushButton *upLoad;
    QLabel *fileRoute;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *serUpdateClass)
    {
        if (serUpdateClass->objectName().isEmpty())
            serUpdateClass->setObjectName(QString::fromUtf8("serUpdateClass"));
        serUpdateClass->resize(632, 261);
        centralWidget = new QWidget(serUpdateClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 30, 81, 21));
        serList = new QComboBox(centralWidget);
        serList->setObjectName(QString::fromUtf8("serList"));
        serList->setGeometry(QRect(120, 30, 171, 22));
        serConnect = new QPushButton(centralWidget);
        serConnect->setObjectName(QString::fromUtf8("serConnect"));
        serConnect->setGeometry(QRect(340, 30, 93, 28));
        openFile = new QPushButton(centralWidget);
        openFile->setObjectName(QString::fromUtf8("openFile"));
        openFile->setGeometry(QRect(470, 30, 93, 28));
        bootloadVer = new QLabel(centralWidget);
        bootloadVer->setObjectName(QString::fromUtf8("bootloadVer"));
        bootloadVer->setGeometry(QRect(20, 70, 271, 16));
        deviceID = new QLabel(centralWidget);
        deviceID->setObjectName(QString::fromUtf8("deviceID"));
        deviceID->setGeometry(QRect(20, 120, 281, 16));
        downloadStatus = new QLabel(centralWidget);
        downloadStatus->setObjectName(QString::fromUtf8("downloadStatus"));
        downloadStatus->setGeometry(QRect(20, 170, 271, 16));
        downloadProgress = new QProgressBar(centralWidget);
        downloadProgress->setObjectName(QString::fromUtf8("downloadProgress"));
        downloadProgress->setGeometry(QRect(340, 80, 118, 23));
        downloadProgress->setValue(0);
        upLoad = new QPushButton(centralWidget);
        upLoad->setObjectName(QString::fromUtf8("upLoad"));
        upLoad->setGeometry(QRect(470, 150, 93, 28));
        fileRoute = new QLabel(centralWidget);
        fileRoute->setObjectName(QString::fromUtf8("fileRoute"));
        fileRoute->setGeometry(QRect(20, 210, 581, 21));
        serUpdateClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(serUpdateClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        serUpdateClass->setStatusBar(statusBar);

        retranslateUi(serUpdateClass);

        QMetaObject::connectSlotsByName(serUpdateClass);
    } // setupUi

    void retranslateUi(QMainWindow *serUpdateClass)
    {
        serUpdateClass->setWindowTitle(QApplication::translate("serUpdateClass", "serUpdate", nullptr));
        label->setText(QApplication::translate("serUpdateClass", "\344\270\262\345\217\243\345\210\227\350\241\250", nullptr));
        serConnect->setText(QApplication::translate("serUpdateClass", "\350\277\236\346\216\245\344\270\262\345\217\243", nullptr));
        openFile->setText(QApplication::translate("serUpdateClass", "\346\211\223\345\274\200\346\226\207\344\273\266", nullptr));
        bootloadVer->setText(QApplication::translate("serUpdateClass", "bootload\347\211\210\346\234\254\345\217\267", nullptr));
        deviceID->setText(QApplication::translate("serUpdateClass", "\350\212\257\347\211\207\345\207\272\345\234\272ID", nullptr));
        downloadStatus->setText(QApplication::translate("serUpdateClass", "\346\234\252\345\274\200\345\247\213", nullptr));
        upLoad->setText(QApplication::translate("serUpdateClass", "\345\274\200\345\247\213\344\270\213\350\275\275", nullptr));
        fileRoute->setText(QApplication::translate("serUpdateClass", "\346\226\207\344\273\266\346\234\252\350\275\275\345\205\245", nullptr));
    } // retranslateUi

};

namespace Ui {
    class serUpdateClass: public Ui_serUpdateClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SERUPDATE_H
