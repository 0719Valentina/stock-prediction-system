#include "child2.h"
#include "ui_child2.h"
#include "qcustomplot.h"
#include <set>

Child2::Child2(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Child2)
{
    ui->setupUi(this);
}

Child2::Child2(QWidget *parent, Stock s)
    : QWidget(parent), stock(s)
    , ui(new Ui::Child2)
{
    ui->setupUi(this);
    customPlot = new QCustomPlot(ui->plotWidget);
    layout = new QVBoxLayout(ui->plotWidget);
    layout->addWidget(customPlot);
    ui->plotWidget->setLayout(layout);
    customPlot->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
}


Child2::~Child2()
{
    delete ui;
}

void Child2::on_lineEdit_editingFinished()
{
    QString text = ui->lineEdit->displayText();
    date=text.toStdString();

    /*根据date计算偏移*/
    long offset=stock.getOffset(date);
    selectStock=stock.readByOffset2(offset);

    std::vector<std::string> names=nameByStock();//获取股票名称

    /*添加下拉框选项*/
    for(auto n:names){
        ui->comboBox->addItem(QString::fromStdString(n));
    }
}

std::vector<std::string> Child2::nameByStock()
{
    std::set<std::string> uniqueNames;
    for (const auto& stock : selectStock) {
        uniqueNames.insert(stock.getCode());
    }

    std::vector<std::string> result(uniqueNames.begin(), uniqueNames.end());
    return result;
}

void Child2::on_comboBox_textActivated(const QString &arg1)
{
    std::string name = arg1.toStdString();
    stockList.push_back(name);
    confirm++;
    if(confirm>=10){
        // this->close();
        Button2();}
    QMessageBox::information(this, "Information", "clicked " + QString::number(confirm));
}


void Child2::Button2(){
    /*从selectData中选出用户要的数据*/
    /*code->vector<Stock*/
    std::map<std::string, std::vector<Stock>> data;
    for(int i=0;i<stockList.size();i++)//创建键
        data[stockList[i]]={};

    // cout<<stockList.size()<<endl;
    for (const auto& s : selectStock) {
        if (data.find(s.getCode()) != data.end()) {
            data[s.getCode()].push_back((s));
        }
    }
    /*计算股票的隔天收益率序列*/
    std::map<std::string, std::vector<double>> returns;
    for(auto it=data.begin(); it!=data.end(); it++){
        std::string name=it->first;
        std::vector<Stock> toCalculate=it->second;
        std::vector<double> thisData=dailyReturn(toCalculate);
        returns[name]=thisData;
    }
    visualizeData((returns));
}

double calculatePearson(const std::vector<double>& x, const std::vector<double>& y) {
    int n = x.size();
    double sumX = 0.0, sumY = 0.0, sumXY = 0.0, sumX2 = 0.0, sumY2 = 0.0;
    for (int i = 0; i < n; ++i) {
        sumX += x[i];
        sumY += y[i];
        sumXY += x[i] * y[i];
        sumX2 += x[i] * x[i];
        sumY2 += y[i] * y[i];
    }
    double d = sqrt((n * sumX2 - sumX * sumX) * (n * sumY2 - sumY * sumY));
    if (d == 0) {
        return std::numeric_limits<double>::quiet_NaN(); // 如果分母为0，返回 NaN
    }
    return (n * sumXY - sumX * sumY) / d;
}

void Child2::visualizeData(std::map<std::string, std::vector<double>> data)
{
    int n = data.size();
    QVector<QVector<double>> correlationMatrix(n, QVector<double>(n, 0.0));
    int i = 0, j = 0;
    for (const auto& entry1 : data) {
        j = 0;
        for (const auto& entry2 : data) {
            correlationMatrix[i][j] = calculatePearson(entry1.second, entry2.second);
            ++j;
        }
        ++i;
    }

    /*设置坐标轴标签*/
    QSharedPointer<QCPAxisTickerText> textTicker(new QCPAxisTickerText);
    int cnt=0;
    for(auto i=data.begin(); i!=data.end(); i++){
        cnt++;
        textTicker->addTick(cnt-0.5, QString::fromStdString(i->first));
    }

    customPlot->xAxis->setTicker(textTicker);
    customPlot->xAxis->setRange(0,10,Qt::AlignLeft);
    customPlot->xAxis->setTickLength(2,0);
    customPlot->yAxis->setTicker(textTicker);
    customPlot->yAxis->setRange(0,10,Qt::AlignLeft);
    customPlot->yAxis->setTickLength(2,0);

    QCPColorMap *heatmap = new QCPColorMap(customPlot->xAxis,customPlot->yAxis);
    heatmap->data()->setSize(n,n);
    heatmap->data()->setRange(QCPRange(0.5,9.5), QCPRange(0.5,9.5));

    for(int x=0;x<n;x++)
    {
        for(int y=0;y<n;y++)
        {
            heatmap->data()->setCell(x, y, correlationMatrix[x][y]);
            // 在每个单元格中显示相关系数
            QCPItemText *textItem = new QCPItemText(customPlot);
            textItem->setPositionAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
            textItem->setFont(QFont(font().family(), 8));
            textItem->setSelectable(false);

            QString text = QString::number(correlationMatrix[x][y], 'f', 2);
            textItem->setText(text);
            textItem->position->setCoords(x + 0.5, y + 0.5);
        }
    }

    QCPColorScale *colorScale = new QCPColorScale(customPlot);
    colorScale->setType(QCPAxis::atBottom);
    customPlot->plotLayout()->addElement(1, 0, colorScale);
    heatmap->setColorScale(colorScale);
    QCPColorGradient gradient;
    gradient.setColorStopAt(-1.0, QColor("#54ff9f"));
    gradient.setColorStopAt(0, QColor("#f6efa6"));
    gradient.setColorStopAt(1.0, QColor("#cd2626"));
    heatmap->setGradient(gradient);
    //heatmap->rescaleDataRange();
    heatmap->setDataRange(QCPRange(-1, 1));
    heatmap->setInterpolate(false);

    QCPMarginGroup *marginGroup = new QCPMarginGroup(customPlot);
    customPlot->axisRect()->setMarginGroup(QCP::msLeft | QCP::msRight, marginGroup);
    colorScale->setMarginGroup(QCP::msLeft | QCP::msRight, marginGroup);

    customPlot->replot(QCustomPlot::rpQueuedReplot);
}
