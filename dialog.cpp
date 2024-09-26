#include "dialog.h"
#include "ui_dialog.h"
#include "child1.h"
#include "child2.h"
#include "predict.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::dialog)
{
    ui->setupUi(this);
}

Dialog::Dialog(QWidget *parent, Stock stockPtr)
    :QDialog(parent), stock(stockPtr)
    ,ui(new Ui::dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_pushButton_clicked()
{
    Child1 *child1 = new Child1(nullptr,stock);
    //cout<<stock.getOutput()<<endl;
    child1->show();
}


void Dialog::on_pushButton_2_clicked()
{
    Child2 *child2 = new Child2(nullptr, stock);
    child2->show();
}


void Dialog::on_pushButton_3_clicked()
{
    Predict *predict = new Predict(nullptr, stock);
    predict->show();
}

