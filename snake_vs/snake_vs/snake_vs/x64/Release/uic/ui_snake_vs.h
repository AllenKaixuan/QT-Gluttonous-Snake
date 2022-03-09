/********************************************************************************
** Form generated from reading UI file 'snake_vs.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SNAKE_VS_H
#define UI_SNAKE_VS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_snake_vsClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *snake_vsClass)
    {
        if (snake_vsClass->objectName().isEmpty())
            snake_vsClass->setObjectName(QString::fromUtf8("snake_vsClass"));
        snake_vsClass->resize(600, 400);
        menuBar = new QMenuBar(snake_vsClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        snake_vsClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(snake_vsClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        snake_vsClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(snake_vsClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        snake_vsClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(snake_vsClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        snake_vsClass->setStatusBar(statusBar);

        retranslateUi(snake_vsClass);

        QMetaObject::connectSlotsByName(snake_vsClass);
    } // setupUi

    void retranslateUi(QMainWindow *snake_vsClass)
    {
        snake_vsClass->setWindowTitle(QCoreApplication::translate("snake_vsClass", "snake_vs", nullptr));
    } // retranslateUi

};

namespace Ui {
    class snake_vsClass: public Ui_snake_vsClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SNAKE_VS_H
