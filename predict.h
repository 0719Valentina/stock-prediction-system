#ifndef PREDICT_H
#define PREDICT_H

#include <QWidget>
#include "stock.h"
#include <QVBoxLayout>
#include <string>
#include "dlib/svm.h"
#include "qcustomplot.h"

using namespace dlib;

namespace Ui {
class Predict;
}

class Predict : public QWidget
{
    Q_OBJECT

public:
    explicit Predict(QWidget *parent = nullptr);
    explicit Predict(QWidget *parent, Stock s);
    void toPredict();
    void train_init();//训练数据采用该只股票的所有日期
    void visualizeData();
    double RMSE();
    ~Predict();

private slots:
    void on_lineEdit_editingFinished();

    void on_lineEdit_2_editingFinished();

    void on_buttonBox_accepted();

private:
    QCustomPlot *customPlot;
    Ui::Predict *ui;
    Stock stock;
    QVBoxLayout* layout;
    std::string code;
    std::string date;
    std::string date0;//前2个月
    std::string date1;//前一个月
    std::string date2; //下个月的日期
    std::vector<Stock> trueValue; //下个月真实价格
    std::vector<double> value; //预测值
    std::vector<std::string> X; //坐标日期
    std::vector<double> y;//真实值

    typedef matrix<double,1,1> sample_type;
    sample_type m;
    std::vector<sample_type> samples;
    std::vector<double> label;
    typedef radial_basis_kernel<sample_type> kernel_type;
    rvm_regression_trainer<kernel_type> trainer;
    decision_function<kernel_type> test;
};

#endif // PREDICT_H
