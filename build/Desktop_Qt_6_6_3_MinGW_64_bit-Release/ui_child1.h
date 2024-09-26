/********************************************************************************
** Form generated from reading UI file 'child1.ui'
**
** Created by: Qt User Interface Compiler version 6.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHILD1_H
#define UI_CHILD1_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Child1
{
public:
    QGridLayout *gridLayout;
    QLabel *label_2;
    QLineEdit *lineEdit_2;
    QDialogButtonBox *buttonBox;
    QLineEdit *lineEdit;
    QLabel *label_3;
    QGraphicsView *plotWidget;
    QLabel *label;

    void setupUi(QWidget *Child1)
    {
        if (Child1->objectName().isEmpty())
            Child1->setObjectName("Child1");
        Child1->resize(624, 414);
        Child1->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"background-color: rgb(233, 231, 227);\n"
""));
        gridLayout = new QGridLayout(Child1);
        gridLayout->setObjectName("gridLayout");
        label_2 = new QLabel(Child1);
        label_2->setObjectName("label_2");
        label_2->setStyleSheet(QString::fromUtf8("font: 12pt \"\346\245\267\344\275\223\";\n"
"background-color: transparent;"));

        gridLayout->addWidget(label_2, 2, 0, 1, 1);

        lineEdit_2 = new QLineEdit(Child1);
        lineEdit_2->setObjectName("lineEdit_2");
        lineEdit_2->setStyleSheet(QString::fromUtf8("background-color: rgb(233, 231, 227);\n"
"background-color: rgb(255, 255, 255);\n"
"border-color: rgb(160, 160, 160);\n"
""));

        gridLayout->addWidget(lineEdit_2, 2, 4, 1, 1);

        buttonBox = new QDialogButtonBox(Child1);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout->addWidget(buttonBox, 4, 3, 1, 2);

        lineEdit = new QLineEdit(Child1);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

        gridLayout->addWidget(lineEdit, 2, 1, 1, 1);

        label_3 = new QLabel(Child1);
        label_3->setObjectName("label_3");
        label_3->setStyleSheet(QString::fromUtf8("font: 12pt \"\346\245\267\344\275\223\";\n"
"background-color: transparent;"));

        gridLayout->addWidget(label_3, 2, 2, 1, 2);

        plotWidget = new QGraphicsView(Child1);
        plotWidget->setObjectName("plotWidget");
        plotWidget->setStyleSheet(QString::fromUtf8("background-color: rgb(233, 231, 227);\n"
"background-color: rgb(255, 255, 255);\n"
"border-color: rgb(160, 160, 160);\n"
""));
        plotWidget->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContentsOnFirstShow);

        gridLayout->addWidget(plotWidget, 3, 0, 1, 5);

        label = new QLabel(Child1);
        label->setObjectName("label");
        label->setStyleSheet(QString::fromUtf8("font: 14pt \"\346\245\267\344\275\223\";\n"
"background-color: transparent;"));

        gridLayout->addWidget(label, 0, 0, 1, 1);


        retranslateUi(Child1);

        QMetaObject::connectSlotsByName(Child1);
    } // setupUi

    void retranslateUi(QWidget *Child1)
    {
        Child1->setWindowTitle(QCoreApplication::translate("Child1", "\350\202\241\347\245\250\344\273\267\346\240\274K\347\272\277\345\233\276", nullptr));
        label_2->setText(QCoreApplication::translate("Child1", "\350\257\267\350\276\223\345\205\245\350\202\241\347\245\250\344\273\243\347\240\201\357\274\232", nullptr));
        label_3->setText(QCoreApplication::translate("Child1", "\350\257\267\350\276\223\345\205\245\350\202\241\347\245\250\346\227\245\346\234\237\357\274\232", nullptr));
        label->setText(QCoreApplication::translate("Child1", "\350\202\241\347\245\250\344\273\267\346\240\274\345\217\257\350\247\206\345\214\226", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Child1: public Ui_Child1 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHILD1_H
