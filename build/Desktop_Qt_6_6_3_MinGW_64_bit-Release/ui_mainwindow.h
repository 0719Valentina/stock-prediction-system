/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCommandLinkButton>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QCommandLinkButton *commandLinkButton;
    QCommandLinkButton *commandLinkButton_2;
    QCommandLinkButton *commandLinkButton_3;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        commandLinkButton = new QCommandLinkButton(centralwidget);
        commandLinkButton->setObjectName("commandLinkButton");
        commandLinkButton->setGeometry(QRect(200, 160, 168, 41));
        commandLinkButton_2 = new QCommandLinkButton(centralwidget);
        commandLinkButton_2->setObjectName("commandLinkButton_2");
        commandLinkButton_2->setGeometry(QRect(210, 120, 168, 41));
        commandLinkButton_3 = new QCommandLinkButton(centralwidget);
        commandLinkButton_3->setObjectName("commandLinkButton_3");
        commandLinkButton_3->setGeometry(QRect(230, 70, 168, 41));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 19));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        commandLinkButton->setText(QCoreApplication::translate("MainWindow", "\345\275\223\346\234\210\344\273\267\346\240\274K\347\272\277\345\233\276", nullptr));
        commandLinkButton_2->setText(QCoreApplication::translate("MainWindow", "\347\233\270\345\205\263\347\263\273\346\225\260\350\256\241\347\256\227\345\217\212\347\203\255\345\212\233\345\233\276\345\261\225\347\244\272", nullptr));
        commandLinkButton_3->setText(QCoreApplication::translate("MainWindow", "\350\202\241\347\245\250\344\273\267\346\240\274\351\242\204\346\265\213", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
