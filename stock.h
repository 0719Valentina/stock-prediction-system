#ifndef STOCK_H
#define STOCK_H

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <map>
#include <queue>
class MinNode;

class Stock
{
public:
    Stock(){}
    Stock(const std::string& i, const std::string& o, const std::string& index):inputFile(i),outputPath(o),indexFile(index){}
    const std::string& getCode() const{return ts_code;}
    const std::string& getDate() const{return trade_date;}
    void externSort(); //外排序
    void split();//分割成块
    void merge(const std::vector<std::string>& names);//有序块合并
    void setInfo(const std::vector<std::string>& info); //依次设置股票信息
    void Write(std::vector<Stock>& buffer, std::ofstream& file, bool isOn); //写入输出文件
    void createIndex(); //创建索引
    long getOffset(const std::string& code, const std::string& date) const;//根据股票代码和日期返回索引表偏移
    long getOffset(const std::string& date) const;//根据股票日期返回索引表偏移
    long getOffsetByCode(const std::string& code) const;
    std::vector<Stock> readByOffset(long offset); //根据索引表偏移读取股票数据
    std::vector<Stock> readByOffset2(long offset); //根据索引表偏移读取股票数据
    std::vector<Stock> readByOffset3(long offset);
    std::vector<Stock> readBySize(long offset, int size);
    const std::string& getOutput() const{return outputPath;}
    const std::string& getOpen() const{return open;}
    const std::string& getHigh() const{return high;}
    const std::string& getLow() const{return low;}
    const std::string& getClose() const{return close;}


private:
    /*单只股票*/
    std::string ts_code; //股票代码
    std::string trade_date; //交易日期
    std::string open; //开盘价
    std::string high; //最高价
    std::string low; //最低价
    std::string close; //收盘价
    std::string pre_close; //临近收盘价
    std::string change; //涨跌幅
    std::string pct_chg; //涨跌百分比
    std::string vol; //交易量
    std::string amount; //交易金额

    std::string inputFile; //输入文件名
    std::string outputPath; //输出路径
    std::string indexFile; //索引文件名

    std::map<std::pair<std::string, std::string>, long> indexMap; //索引表
    std::map<std::string, long> indexMap2;//只依据日期的索引表
    std::map<std::string, long> indexMap3; //只依据代码的偏移
    std::vector<std::streamoff> offsets; //存储行的偏移

    static bool compareStock(const Stock& s1, const Stock& s2){
        /*先比较股票代码*/
        if(s1.ts_code != s2.ts_code){
            return s1.ts_code < s2.ts_code;
        }
        else{/*再比较交易日期*/
            return s1.trade_date < s2.trade_date;
        }
    }
};

std::vector<double> dailyReturn(const std::vector<Stock>& data);//计算一只股票的隔天收益率

#endif // STOCK_H
