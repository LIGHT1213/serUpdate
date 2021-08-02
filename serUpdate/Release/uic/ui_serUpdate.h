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
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_serUpdateClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *serUpdateClass)
    {
        if (serUpdateClass->objectName().isEmpty())
            serUpdateClass->setObjectName(QString::fromUtf8("serUpdateClass"));
        serUpdateClass->resize(600, 400);
        menuBar = new QMenuBar(serUpdateClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        serUpdateClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(serUpdateClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        serUpdateClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(serUpdateClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
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
    } // retranslateUi

};

namespace Ui {
    class serUpdateClass: public Ui_serUpdateClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SERUPDATE_H
