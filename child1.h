#ifndef CHILD1_H
#define CHILD1_H
#include <QWidget>
#include <string>
#include "stock.h"
#include <QVBoxLayout>
#include "qcustomplot.h"

namespace Ui {
class Child1;
}

class Child1 : public QWidget
{
    Q_OBJECT

public:
    explicit Child1(QWidget *parent = nullptr);
    explicit Child1(QWidget *parent, Stock s);
    void visualizeData(const std::vector<Stock>& data);
    ~Child1();

private slots:
    void on_lineEdit_editingFinished();

    void on_lineEdit_2_editingFinished();

    void on_buttonBox_accepted();

private:
    Ui::Child1 *ui;
    std::string code;
    std::string date;
    Stock stock;
    QCustomPlot *plot;
    QVBoxLayout *layout;
};

#endif // CHILD1_H
