/********************************************************************************
** Form generated from reading UI file 'dialog.ui'
**
** Created by: Qt User Interface Compiler version 6.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_H
#define UI_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_dialog
{
public:
    QFrame *frame;
    QFrame *frame_2;
    QLabel *label;
    QLabel *label_2;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;

    void setupUi(QDialog *dialog)
    {
        if (dialog->objectName().isEmpty())
            dialog->setObjectName("dialog");
        dialog->resize(474, 428);
        dialog->setStyleSheet(QString::fromUtf8(""));
        frame = new QFrame(dialog);
        frame->setObjectName("frame");
        frame->setGeometry(QRect(-20, 0, 501, 431));
        frame->setStyleSheet(QString::fromUtf8("*{\n"
"	background-color: rgb(255, 255, 255);\n"
"}\n"
"\n"
"QFrame#frame{\n"
"	border-image: url(:/new/prefix1/pic1.jpg);\n"
"}\n"
"\n"
"#frame_2{\n"
"border-radius:30px;\n"
"	background-color: rgba(169, 169, 169, 160);\n"
"}\n"
"\n"
"QLabel#label{\n"
"	border-radius:30px;\n"
"	background-color: rgba(122, 122, 122, 200);\n"
"}\n"
"\n"
"#label_2{\n"
"	background: transparent;\n"
"	color:rgba(255, 255, 255, 200);\n"
"	font: 14pt \"\346\245\267\344\275\223\";\n"
"}\n"
"\n"
"QPushButton#pushButton{\n"
"	border-radius:10px;\n"
"	\n"
"	font: 12pt \"\346\245\267\344\275\223\";\n"
"	background-color: rgb(255, 255, 222);\n"
"}\n"
"\n"
"#pushButton_2{\n"
"	border-radius:10px;\n"
"	\n"
"	font: 12pt \"\346\245\267\344\275\223\";\n"
"	background-color: rgb(255, 255, 222);\n"
"}\n"
"\n"
"#pushButton_3{\n"
"	border-radius:10px;\n"
"	\n"
"	font: 12pt \"\346\245\267\344\275\223\";\n"
"	background-color: rgb(255, 255, 222);\n"
"}\n"
""));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        frame_2 = new QFrame(frame);
        frame_2->setObjectName("frame_2");
        frame_2->setGeometry(QRect(10, -10, 511, 451));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        label = new QLabel(frame_2);
        label->setObjectName("label");
        label->setGeometry(QRect(100, 130, 301, 271));
        label_2 = new QLabel(frame_2);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(180, 150, 151, 31));
        QFont font;
        font.setFamilies({QString::fromUtf8("\346\245\267\344\275\223")});
        font.setPointSize(14);
        font.setBold(false);
        font.setItalic(false);
        label_2->setFont(font);
        pushButton = new QPushButton(frame_2);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(160, 210, 161, 31));
        pushButton_2 = new QPushButton(frame_2);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(160, 270, 161, 31));
        pushButton_3 = new QPushButton(frame_2);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(160, 330, 161, 31));

        retranslateUi(dialog);

        QMetaObject::connectSlotsByName(dialog);
    } // setupUi

    void retranslateUi(QDialog *dialog)
    {
        dialog->setWindowTitle(QCoreApplication::translate("dialog", "Dialog", nullptr));
        label->setText(QString());
        label_2->setText(QCoreApplication::translate("dialog", "\350\202\241\347\245\250\347\263\273\347\273\237\345\212\237\350\203\275\351\200\211\346\213\251", nullptr));
        pushButton->setText(QCoreApplication::translate("dialog", "\345\275\223\346\234\210\344\273\267\346\240\274K\347\272\277\345\233\276", nullptr));
        pushButton_2->setText(QCoreApplication::translate("dialog", "\347\233\270\345\205\263\347\263\273\346\225\260\350\256\241\347\256\227\345\217\212\347\203\255\345\212\233\345\233\276", nullptr));
        pushButton_3->setText(QCoreApplication::translate("dialog", "\344\270\213\346\234\210\350\202\241\344\273\267\351\242\204\346\265\213", nullptr));
    } // retranslateUi

};

namespace Ui {
    class dialog: public Ui_dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H
