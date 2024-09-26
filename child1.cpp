#include "child1.h"
#include "ui_child1.h"
#include <iostream>
#include <QMessageBox>
#include <QMainWindow>

Child1::Child1(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Child1)
{
    layout=new QVBoxLayout(this);
    ui->setupUi(this);
}

Child1::Child1(QWidget *parent, Stock s)
    : QWidget(parent), stock(s)
    , ui(new Ui::Child1)
{
    ui->setupUi(this);
    plot = new QCustomPlot(ui->plotWidget);
    layout = new QVBoxLayout(ui->plotWidget);
    layout->addWidget(plot);
    ui->plotWidget->setLayout(layout);
    plot->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
}

Child1::~Child1()
{
    delete ui;
}

void Child1::on_lineEdit_editingFinished()
{
    QString text = ui->lineEdit->displayText();
    code=text.toStdString();
}


void Child1::on_lineEdit_2_editingFinished()
{
    QString text = ui->lineEdit_2->displayText();
    date=text.toStdString();
}


void Child1::on_buttonBox_accepted()
{
    /*根据code和date计算偏移*/
    long offset=stock.getOffset(code,date);
    std::vector<Stock> data=stock.readByOffset(offset);
    if(data.size()!=0)
        visualizeData(data);
    else{
        QMessageBox::warning(this, "Data Not Found","No data found for the stock code and date.");
    }
}

void Child1::visualizeData(const std::vector<Stock>& data)
{
    const QColor BrushPositive("#ec0000");
    const QColor PenPositive("#8a0000");
    const QColor BrushNegative("#00da3c");
    const QColor PenNegative("#008f28");

    // 清除先前的绘图数据
    plot->clearPlottables();

    QVector<double> open, high, low, close;
    QVector<QString> x;

    for (const auto &record : data) {
        QDate date = QDate::fromString(QString::fromStdString(record.getDate()), "yyyyMMdd");
        double openPrice = QString::fromStdString(record.getOpen()).toDouble();
        double highPrice = QString::fromStdString(record.getHigh()).toDouble();
        double lowPrice = QString::fromStdString(record.getLow()).toDouble();
        double closePrice = QString::fromStdString(record.getClose()).toDouble();

        x.append(date.toString("yyyy-MM-dd"));
        open.append(openPrice);
        high.append(highPrice);
        low.append(lowPrice);
        close.append(closePrice);
    }

    QSharedPointer<QCPAxisTickerText> textTicker(new QCPAxisTickerText);
    textTicker->setTickCount(10);
    QCPDataContainer<QCPFinancialData> datas;

    for (int i = 0; i < x.size(); ++i) {
        QCPFinancialData data;
        data.key = i;
        data.open = open[i];
        data.low = low[i];
        data.high = high[i];
        data.close = close[i];
        datas.add(data);
    }
    for (int i = 0; i < x.size(); ++i) {
        QString dateString = x[i];
        textTicker->addTick(i, dateString);
    }
    QCPFinancial *financial = new QCPFinancial(plot->xAxis, plot->yAxis);
    financial->setName("当月K线图");
    financial->setBrushPositive(BrushPositive);
    financial->setPenPositive(PenPositive);
    financial->setBrushNegative(BrushNegative);
    financial->setPenNegative(PenNegative);
    financial->data()->set(datas);

    plot->xAxis->setTicker(textTicker);
    plot->rescaleAxes();
    plot->xAxis->scaleRange(1.05, plot->xAxis->range().center());
    plot->yAxis->scaleRange(1.05, plot->yAxis->range().center());
    plot->legend->setVisible(true);

    plot->replot();
}

