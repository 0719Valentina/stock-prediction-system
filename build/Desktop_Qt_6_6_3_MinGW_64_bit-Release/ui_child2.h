/********************************************************************************
** Form generated from reading UI file 'child2.ui'
**
** Created by: Qt User Interface Compiler version 6.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHILD2_H
#define UI_CHILD2_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Child2
{
public:
    QGridLayout *gridLayout;
    QLabel *label_2;
    QLineEdit *lineEdit;
    QLabel *label;
    QComboBox *comboBox;
    QGraphicsView *plotWidget;
    QDialogButtonBox *buttonBox;

    void setupUi(QWidget *Child2)
    {
        if (Child2->objectName().isEmpty())
            Child2->setObjectName("Child2");
        Child2->resize(399, 254);
        Child2->setStyleSheet(QString::fromUtf8("\n"
"font: 10pt \"\346\245\267\344\275\223\";\n"
"background-color: rgb(233, 231, 227);"));
        gridLayout = new QGridLayout(Child2);
        gridLayout->setObjectName("gridLayout");
        label_2 = new QLabel(Child2);
        label_2->setObjectName("label_2");
        label_2->setStyleSheet(QString::fromUtf8("font: 10pt \"\346\245\267\344\275\223\";"));

        gridLayout->addWidget(label_2, 0, 0, 1, 1);

        lineEdit = new QLineEdit(Child2);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setStyleSheet(QString::fromUtf8("background-color: rgb(233, 231, 227);\n"
"background-color: rgb(255, 255, 255);\n"
"border-color: rgb(160, 160, 160);\n"
""));

        gridLayout->addWidget(lineEdit, 0, 1, 1, 1);

        label = new QLabel(Child2);
        label->setObjectName("label");

        gridLayout->addWidget(label, 0, 2, 1, 1);

        comboBox = new QComboBox(Child2);
        comboBox->setObjectName("comboBox");
        comboBox->setStyleSheet(QString::fromUtf8("background-color: rgb(233, 231, 227);\n"
"background-color: rgb(255, 255, 255);\n"
"border-color: rgb(160, 160, 160);\n"
""));

        gridLayout->addWidget(comboBox, 0, 3, 1, 1);

        plotWidget = new QGraphicsView(Child2);
        plotWidget->setObjectName("plotWidget");
        plotWidget->setStyleSheet(QString::fromUtf8("background-color: rgb(233, 231, 227);\n"
"background-color: rgb(255, 255, 255);\n"
"border-color: rgb(160, 160, 160);\n"
""));

        gridLayout->addWidget(plotWidget, 1, 0, 1, 4);

        buttonBox = new QDialogButtonBox(Child2);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout->addWidget(buttonBox, 2, 3, 1, 1);


        retranslateUi(Child2);

        QMetaObject::connectSlotsByName(Child2);
    } // setupUi

    void retranslateUi(QWidget *Child2)
    {
        Child2->setWindowTitle(QCoreApplication::translate("Child2", "\347\233\270\345\205\263\347\263\273\346\225\260\350\256\241\347\256\227\345\217\212\347\203\255\345\212\233\345\233\276\345\261\225\347\244\272", nullptr));
        label_2->setText(QCoreApplication::translate("Child2", "\350\257\267\350\276\223\345\205\245\350\202\241\347\245\250\346\227\245\346\234\237", nullptr));
        label->setText(QCoreApplication::translate("Child2", "\351\200\211\346\213\251\350\202\241\347\245\250\344\273\243\347\240\201", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Child2: public Ui_Child2 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHILD2_H
