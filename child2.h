#ifndef CHILD2_H
#define CHILD2_H

#include <QWidget>
#include <QMessageBox>
#include <QFontComboBox>
#include "stock.h"
#include <QLayout>
#include "qcustomplot.h"

namespace Ui {
class Child2;
}

class Child2 : public QWidget
{
    Q_OBJECT

public:
    explicit Child2(QWidget *parent = nullptr);
    explicit Child2(QWidget *parent, Stock s);
    std::vector<std::string> nameByStock();//返回不重复的股票代码
    void Button2();
    void visualizeData(std::map<std::string, std::vector<double>> data);
    ~Child2();

private slots:
    void on_lineEdit_editingFinished();

    void on_comboBox_textActivated(const QString &arg1);

private:
    QCustomPlot *customPlot;
    Ui::Child2 *ui;
    std::string date;
    Stock stock;
    QVBoxLayout *layout;
    std::vector<std::string> stockList;
    std::vector<Stock> selectStock;
    int confirm=0;
};

double calculatePearson(const std::vector<double>& x, const std::vector<double>& y);

#endif // CHILD2_H
