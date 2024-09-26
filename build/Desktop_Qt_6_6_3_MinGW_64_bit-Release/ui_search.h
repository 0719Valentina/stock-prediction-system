/********************************************************************************
** Form generated from reading UI file 'search.ui'
**
** Created by: Qt User Interface Compiler version 6.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SEARCH_H
#define UI_SEARCH_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Search
{
public:
    QLabel *label;
    QComboBox *comboBox;

    void setupUi(QWidget *Search)
    {
        if (Search->objectName().isEmpty())
            Search->setObjectName("Search");
        Search->resize(213, 108);
        Search->setStyleSheet(QString::fromUtf8("background-color: rgb(248, 255, 110);\n"
"border-color: rgb(255, 255, 29);\n"
"background-color: rgb(212, 224, 151);"));
        label = new QLabel(Search);
        label->setObjectName("label");
        label->setGeometry(QRect(30, 40, 49, 14));
        comboBox = new QComboBox(Search);
        comboBox->setObjectName("comboBox");
        comboBox->setGeometry(QRect(90, 40, 70, 22));

        retranslateUi(Search);

        QMetaObject::connectSlotsByName(Search);
    } // setupUi

    void retranslateUi(QWidget *Search)
    {
        Search->setWindowTitle(QCoreApplication::translate("Search", "Form", nullptr));
        label->setText(QCoreApplication::translate("Search", "<html><head/><body><p align=\"center\"><span style=\" font-weight:700;\">\350\202\241\347\245\250\346\220\234\347\264\242</span></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Search: public Ui_Search {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SEARCH_H
