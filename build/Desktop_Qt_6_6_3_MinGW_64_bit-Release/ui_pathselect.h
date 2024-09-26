/********************************************************************************
** Form generated from reading UI file 'pathselect.ui'
**
** Created by: Qt User Interface Compiler version 6.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PATHSELECT_H
#define UI_PATHSELECT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PathSelect
{
public:
    QWidget *centralwidget;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QGraphicsView *graphicsView;
    QGraphicsView *graphicsView_2;
    QLabel *label;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *PathSelect)
    {
        if (PathSelect->objectName().isEmpty())
            PathSelect->setObjectName("PathSelect");
        PathSelect->resize(393, 238);
        PathSelect->setMaximumSize(QSize(10000, 10000));
        PathSelect->setStyleSheet(QString::fromUtf8("background-color: rgb(240, 240, 240);\n"
"font: 9pt \"Microsoft YaHei UI\";"));
        centralwidget = new QWidget(PathSelect);
        centralwidget->setObjectName("centralwidget");
        centralwidget->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(130, 70, 158, 21));
        pushButton->setStyleSheet(QString::fromUtf8("font: 12pt \"\346\245\267\344\275\223\";\n"
"background-color: rgb(215, 215, 215);"));
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(130, 130, 158, 21));
        pushButton_2->setStyleSheet(QString::fromUtf8("font: 12pt \"\346\245\267\344\275\223\";\n"
"background-color: rgb(215, 215, 215);"));
        graphicsView = new QGraphicsView(centralwidget);
        graphicsView->setObjectName("graphicsView");
        graphicsView->setGeometry(QRect(90, 130, 21, 21));
        graphicsView->setStyleSheet(QString::fromUtf8("border-image: url(:/new/prefix1/icon1.png);"));
        graphicsView_2 = new QGraphicsView(centralwidget);
        graphicsView_2->setObjectName("graphicsView_2");
        graphicsView_2->setGeometry(QRect(90, 70, 21, 21));
        graphicsView_2->setStyleSheet(QString::fromUtf8("border-image: url(:/new/prefix1/icon2.jpg);"));
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(160, 10, 121, 20));
        label->setStyleSheet(QString::fromUtf8("font: 18pt \"\346\245\267\344\275\223\";"));
        PathSelect->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(PathSelect);
        statusbar->setObjectName("statusbar");
        PathSelect->setStatusBar(statusbar);

        retranslateUi(PathSelect);

        QMetaObject::connectSlotsByName(PathSelect);
    } // setupUi

    void retranslateUi(QMainWindow *PathSelect)
    {
        PathSelect->setWindowTitle(QCoreApplication::translate("PathSelect", "\350\267\257\345\276\204\351\200\211\346\213\251", nullptr));
        pushButton->setText(QCoreApplication::translate("PathSelect", "\350\257\267\351\200\211\346\213\251\350\202\241\347\245\250\346\226\207\344\273\266", nullptr));
        pushButton_2->setText(QCoreApplication::translate("PathSelect", "\350\257\267\351\200\211\346\213\251\350\276\223\345\207\272\346\226\207\344\273\266\345\244\271", nullptr));
        label->setText(QCoreApplication::translate("PathSelect", "\350\267\257\345\276\204\351\200\211\346\213\251", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PathSelect: public Ui_PathSelect {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PATHSELECT_H
