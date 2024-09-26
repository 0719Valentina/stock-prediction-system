/********************************************************************************
** Form generated from reading UI file 'predict.ui'
**
** Created by: Qt User Interface Compiler version 6.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PREDICT_H
#define UI_PREDICT_H

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

class Ui_Predict
{
public:
    QGridLayout *gridLayout;
    QLabel *label;
    QLineEdit *lineEdit;
    QLabel *label_2;
    QLineEdit *lineEdit_2;
    QGraphicsView *plotWidget;
    QDialogButtonBox *buttonBox;

    void setupUi(QWidget *Predict)
    {
        if (Predict->objectName().isEmpty())
            Predict->setObjectName("Predict");
        Predict->resize(389, 244);
        Predict->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"background-color: rgb(233, 231, 227);\n"
"border-color: rgb(160, 160, 160);\n"
""));
        gridLayout = new QGridLayout(Predict);
        gridLayout->setObjectName("gridLayout");
        label = new QLabel(Predict);
        label->setObjectName("label");
        label->setStyleSheet(QString::fromUtf8("font: 9pt \"\346\245\267\344\275\223\";"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        lineEdit = new QLineEdit(Predict);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setStyleSheet(QString::fromUtf8("background-color: rgb(233, 231, 227);\n"
"background-color: rgb(255, 255, 255);\n"
"border-color: rgb(160, 160, 160);\n"
""));

        gridLayout->addWidget(lineEdit, 0, 1, 1, 1);

        label_2 = new QLabel(Predict);
        label_2->setObjectName("label_2");
        label_2->setStyleSheet(QString::fromUtf8("font: 9pt \"\346\245\267\344\275\223\";"));

        gridLayout->addWidget(label_2, 0, 2, 1, 1);

        lineEdit_2 = new QLineEdit(Predict);
        lineEdit_2->setObjectName("lineEdit_2");
        lineEdit_2->setStyleSheet(QString::fromUtf8("background-color: rgb(233, 231, 227);\n"
"background-color: rgb(255, 255, 255);\n"
"border-color: rgb(160, 160, 160);\n"
""));

        gridLayout->addWidget(lineEdit_2, 0, 3, 1, 1);

        plotWidget = new QGraphicsView(Predict);
        plotWidget->setObjectName("plotWidget");
        plotWidget->setStyleSheet(QString::fromUtf8("background-color: rgb(233, 231, 227);\n"
"background-color: rgb(255, 255, 255);\n"
"border-color: rgb(160, 160, 160);\n"
""));

        gridLayout->addWidget(plotWidget, 1, 0, 1, 4);

        buttonBox = new QDialogButtonBox(Predict);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout->addWidget(buttonBox, 2, 3, 1, 1);


        retranslateUi(Predict);

        QMetaObject::connectSlotsByName(Predict);
    } // setupUi

    void retranslateUi(QWidget *Predict)
    {
        Predict->setWindowTitle(QCoreApplication::translate("Predict", "\344\270\213\346\234\210\346\224\266\347\233\230\344\273\267\351\242\204\346\265\213", nullptr));
        label->setText(QCoreApplication::translate("Predict", "<html><head/><body><p>\350\257\267\350\276\223\345\205\245\350\202\241\347\245\250\344\273\243\347\240\201</p></body></html>", nullptr));
        label_2->setText(QCoreApplication::translate("Predict", "<html><head/><body><p>\350\257\267\350\276\223\345\205\245\350\202\241\347\245\250\346\227\245\346\234\237</p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Predict: public Ui_Predict {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PREDICT_H
