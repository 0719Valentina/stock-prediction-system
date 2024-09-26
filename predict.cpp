#include "predict.h"
#include "ui_predict.h"
#include <QMessageBox>
#include <QtCharts>
#include "dlib/svm.h"
#include "qcustomplot.h"

using namespace dlib;

Predict::Predict(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Predict)
{
    ui->setupUi(this);
}

Predict::Predict(QWidget *parent, Stock s)
    :QWidget(parent), stock(s),
    ui(new Ui::Predict)
{
    ui->setupUi(this);
    customPlot = new QCustomPlot(ui->plotWidget);
    layout = new QVBoxLayout(ui->plotWidget);
    layout->addWidget(customPlot);
    ui->plotWidget->setLayout(layout);
    customPlot->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
}

Predict::~Predict()
{
    delete ui;
}

void Predict::on_lineEdit_editingFinished()
{
    QString text = ui->lineEdit->displayText();
    code=text.toStdString();
}

void Predict::on_lineEdit_2_editingFinished()
{
    QString text = ui->lineEdit_2->displayText();
    date=text.toStdString();
    int year, month;
    year = std::stoi(date.substr(0, 4));
    month = std::stoi(date.substr(4, 2));

    month++;
    if (month > 12) {
        month = 1;
        year++;
    }

    std::stringstream ss;
    ss << std::setw(4) << std::setfill('0') << year << std::setw(2) << std::setfill('0') << month;
    date2 = ss.str();

    train_init();//第一行输入结束即可开始训练
    // std::cout<<date2<<std::endl;
}

void Predict::on_buttonBox_accepted()
{
    /*根据code和date计算偏移*/
    long offset=stock.getOffset(code,date2);
    trueValue=stock.readByOffset(offset);
    if(trueValue.size()!=0)
        toPredict();
    else{
        QMessageBox::warning(this, "Data Not Found","No data found for the stock code and date.");
    }
}

void Predict::toPredict()
{
    /*输出跟trueValue一样的维度*/
    for(int i=0; i<trueValue.size(); i++)
    {
        std::string p=trueValue[i].getClose();
        y.push_back(std::stod(p));
        std::string d=trueValue[i].getDate();
        X.push_back(d);

        /*输入是日期 预测价格*/
        m(0)=std::stod(d);
        double output=test(m);
        value.push_back(output);
    }

    visualizeData();
}

void Predict::train_init()
{
    long offset=stock.getOffset(code, date);//本月本只
    long offset2=stock.getOffset(date2); //下月另取一只
    std::vector<Stock> toTrain1=stock.readByOffset(offset);
    std::vector<Stock> toTrain2=stock.readBySize(offset2, 60);
    std::vector<Stock> toTrain = toTrain1;
    toTrain.insert(toTrain.end(), toTrain2.begin(), toTrain2.end());

    //std::cout<<toTrain.size()<<std::endl;

    for(int i=0; i<toTrain.size(); i++)
    {
        m(0)=std::stod(toTrain[i].getDate());
        samples.push_back(m);
        std::string price=toTrain[i].getClose();
        label.push_back(std::stod(price));
    }

    const double gamma=2.0/compute_mean_squared_distance(samples);

    trainer.set_kernel(kernel_type(gamma));
    trainer.set_epsilon(0.001);
    test=trainer.train(samples, label);
}

void Predict::visualizeData()
{
    /*计算RMSE*/
    double result=RMSE();

    QCPGraph *predictedGraph = customPlot->addGraph();
    QCPGraph *actualGraph = customPlot->addGraph();

    QVector<double> x(value.size()), y_predicted(value.size()), y_actual(y.size());

    for (int i = 0; i < value.size(); ++i) {
        x[i] = i; // 使用索引作为 x 轴坐标
        y_predicted[i] = value[i];
    }

    for (int i = 0; i < y.size(); ++i) {
        y_actual[i] = y[i];
    }

    // 设置数据
    predictedGraph->setData(x, y_predicted);
    actualGraph->setData(x, y_actual);

    // 设置线条颜色
    QPen predictedPen(Qt::red);
    QPen actualPen(Qt::blue);
    predictedGraph->setPen(predictedPen);
    actualGraph->setPen(actualPen);

    predictedGraph->setName("Predicted Values");
    actualGraph->setName("Actual Values");

    // 启用图例
    customPlot->legend->setVisible(true);
    QFont legendFont = font();
    legendFont.setPointSize(10);
    customPlot->legend->setFont(legendFont);
    customPlot->legend->setBrush(QBrush(QColor(255, 255, 255, 230)));

    QSharedPointer<QCPAxisTickerText> textTicker(new QCPAxisTickerText);
    for(auto i=0; i<X.size(); i++){
        textTicker->addTick(i+0.5, QString::fromStdString(X[i]));
    }
    customPlot->xAxis->setTicker(textTicker);

    // 设置图表标题和轴标签
    customPlot->plotLayout()->insertRow(0);
    customPlot->plotLayout()->addElement(0, 0, new QCPTextElement(customPlot, "Stock Price Prediction", QFont("sans", 12, QFont::Bold)));
    customPlot->xAxis->setLabel("Date");
    customPlot->yAxis->setLabel("Close Price");

    customPlot->xAxis->setRange(0, value.size() - 1);
    customPlot->yAxis->setRange(*std::min_element(y.begin(), y.end()), *std::max_element(y.begin(), y.end()));

    QCPTextElement *rmseLabel = new QCPTextElement(customPlot, "RMSE: " + QString::number(result), QFont("sans", 10));
    rmseLabel->setTextColor(Qt::red);
    customPlot->plotLayout()->insertRow(1); // 确保新行被插入
    customPlot->plotLayout()->addElement(1, 0, rmseLabel); // 添加到新行

    customPlot->setAntialiasedElements(QCP::aeAll);

    customPlot->replot();
}

double Predict::RMSE()
{
    if (value.size() != y.size()) {
        std::cout << "Error: The size of predictions and labels must be the same." << std::endl;
        exit(1);
    }

    double sum = 0.0;
    for (size_t i = 0; i < value.size(); ++i) {
        double error = value[i] - y[i];
        sum += error * error;
    }

    double rmse = sum / value.size();
    rmse = sqrt(rmse);

    return rmse;
}
