#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include "stock.h"

namespace Ui {
class dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();
    explicit Dialog(QWidget *parent, Stock stockPtr);

private slots:

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::dialog *ui;
    Stock stock;
};

#endif // DIALOG_H
