/********************************************************************************
** Form generated from reading UI file 'snake.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SNAKE_H
#define UI_SNAKE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Snake
{
public:
    QWidget *centralwidget;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Snake)
    {
        if (Snake->objectName().isEmpty())
            Snake->setObjectName(QStringLiteral("Snake"));
        Snake->resize(800, 600);
        centralwidget = new QWidget(Snake);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        Snake->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Snake);
        menubar->setObjectName(QStringLiteral("menubar"));
        Snake->setMenuBar(menubar);
        statusbar = new QStatusBar(Snake);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        Snake->setStatusBar(statusbar);

        retranslateUi(Snake);

        QMetaObject::connectSlotsByName(Snake);
    } // setupUi

    void retranslateUi(QMainWindow *Snake)
    {
        Snake->setWindowTitle(QApplication::translate("Snake", "Snake", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Snake: public Ui_Snake {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SNAKE_H
