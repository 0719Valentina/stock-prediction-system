#include "stock.h"
#include <queue>
#include <QMessageBox>
#include "minnode.h"
#include "minheap.h"

/*内存大小 32MB*/
const int MAX_SIZE = 22*1024*1024;

/*最小堆节点*/

void Stock::split()
{
    std::ifstream input(inputFile);

    std::string prefix=outputPath+"\\block_";
    if(!input){
        std::cout<<"File Open Error:China Stock.csv"<<std::endl;
        exit(1);
    }

    std::string line;
    int cnt=0;//临时文件的编号
    std::vector<Stock> buffer;
    while(getline(input, line)){
        Stock data;
        std::vector<std::string> info;
        std::stringstream ss(line);
        std::string token;
        while(getline(ss, token, ','))
            info.push_back(token);
        data.setInfo(info);
        buffer.push_back(data);

        if(buffer.size()*sizeof(Stock) >= MAX_SIZE){
            cnt++;
            std::string outputName=prefix+std::to_string(cnt)+".txt";
            std::sort(buffer.begin(), buffer.end(), compareStock);
            std::ofstream output(outputName, std::ios::binary);

            if(!output){
                std::cout<<"File Write Error!"<<std::endl;
                exit(1);
            }

            Write(buffer, output,false);
            output.close();
            buffer.clear();
            buffer.shrink_to_fit();
        }
    }
    if(!buffer.empty()){
        cnt++;
        std::string outputName=prefix+std::to_string(cnt)+".txt";
        std::sort(buffer.begin(), buffer.end(), compareStock);
        std::ofstream output(outputName, std::ios::binary);

        if(!output){
            std::cout<<"File Write Error!"<<std::endl;
            exit(1);
        }
        Write(buffer, output,false);
        output.close();
        buffer.clear();
        buffer.shrink_to_fit();
    }
    input.close();
}

void Stock::merge(const std::vector<std::string> &names)
{
    std::string outputName=outputPath + "\\output.txt";
     std::ofstream output(outputName, std::ios::binary);
    /*定义最小堆*/
    minHeap checkMin;
    std::vector<std::ifstream> inputs(names.size());
    /*往最小堆中插入节点*/
    for(int i=0; i<names.size(); i++){
        inputs[i].open(names[i]);
        //std::cout<<"Open"<<std::endl;
        if(!inputs[i]){
            std::cout<<"File Open Error:"<<names[i]<<std::endl;
            exit(1);
        }

        std::string line;
        if(getline(inputs[i],line)){
            //cout<<"h3"<<endl;
            Stock data;
            std::vector<std::string> info;
            std::stringstream ss(line);
            std::string token;
            while (getline(ss, token, ',')) {
                info.push_back(token);
            }
            data.setInfo(info);
            checkMin.push(MinNode(data, i));
        }
    }
    //std::cout<<inputs.capacity()*sizeof(std::ifstream)<<std::endl;
    /*将最小堆中节点写入output*/
    std::vector<Stock> buffer;
    //buffer.reserve(MAX_SIZE/sizeof(Stock));
    while(!checkMin.empty()){
        //std::cout<<minHeap.size()*sizeof(Stock)<<std::endl;
        MinNode min=checkMin.top();
        checkMin.pop();
        Stock toWrite=min.element;
        /*转化为字节流*/
        buffer.push_back(toWrite);

        if(buffer.size()*sizeof(Stock)>=MAX_SIZE*1.2){
            Write(buffer,output,true);
            buffer.clear();
            buffer.shrink_to_fit();
        }

        int i=min.index;
        std::string line;

        if (getline(inputs[i], line)) {
            Stock data;
            std::vector<std::string> info;
            std::stringstream ss(line);
            std::string token;
            while (getline(ss, token, ',')) {
                info.push_back(token);
            }
            data.setInfo(info);
            checkMin.push(MinNode(data, i));
        }
    }
    // 关闭所有文件流
    for (auto& input : inputs) {
        input.close();
    }
    if(!buffer.empty()){
        Write(buffer, output,true);
        buffer.clear();
        buffer.shrink_to_fit();
    }
    output.close();
}

void Stock::externSort()
{
    std::string prefix=outputPath+"\\block_";
    split();
    std::vector<std::string> blocks;

    for (int i = 1; std::ifstream(prefix + std::to_string(i) + ".txt").good(); ++i) {
        blocks.push_back(prefix + std::to_string(i) + ".txt");
    }
    //std::cout<<blocks.size()<<std::endl;
    merge(blocks);
    std::cout<<"End of ExternSort"<<std::endl;
}

void Stock::setInfo(const std::vector<std::string>& info)
{
    if(info.size()==11){
    ts_code=info[0];
    trade_date=info[1];
    open=info[2];
    high=info[3];
    low=info[4];
    close=info[5];
    pre_close=info[6];
    change=info[7];
    pct_chg=info[8];
    vol=info[9];
    amount=info[10];}
    else{
        std::cout<<"Stock Info Error!"<<std::endl;
        exit(1);
    }
}

void Stock::Write(std::vector<Stock>& buffer, std::ofstream& file, bool isOn)
{
    //std::streampos startOffset = file.tellp();
    std::ostringstream oss;
    for(const auto& i: buffer)
    {
        if(isOn){
            //std::streampos lineOffset = file.tellp();
            //offsets.push_back(lineOffset - startOffset);
        }
        oss << i.ts_code << "," << i.trade_date << "," << i.open << ","
            << i.high << "," << i.low << "," << i.close << "," << i.pre_close << ","
            << i.change << "," << i.pct_chg << "," << i.vol << "," << i.amount << "\n";
    }
    std::string data = oss.str();
    file.write(data.c_str(), data.size());
}

void Stock::createIndex()
{
    std::ifstream input(outputPath+"\\output.txt", std::ios::binary);
    std::ofstream index(indexFile);
    if(!input){
        std::cout<<"File Open Error:output.txt"<<std::endl;
        exit(1);
    }
    /*股票代码、日期->offset*/
    long offset=0;
    std::string line;
    std::streamoff offset_file = 0;
    while(getline(input,line)){
        offsets.push_back(offset_file);
        offset_file = input.tellg();
        offset++;
        std::stringstream ss(line);
        std::string code,date;
        getline(ss, code, ',');
        getline(ss, date, ',');
        date=date.substr(0,6); /*日期只要年月*/

        std::pair<std::string,std::string> key=make_pair(code,date);
        if(indexMap.find(key) == indexMap.end())
            indexMap[key]=offset;
        if(indexMap2.find(date) == indexMap2.end())
            indexMap2[date]=offset;
        if(indexMap3.find(code) == indexMap3.end())
            indexMap3[code]=offset;
    }
    /*写入*/
    for(auto& i: indexMap)
        index<<i.first.first<<","<<i.first.second<<","<<"{"<<i.second<<"}"<<std::endl;
    input.close();
    index.close();
}

long Stock::getOffset(const std::string &code, const std::string &date) const{
    auto key = make_pair(code, date);

    if (indexMap.find(key) != indexMap.end()) {
        return indexMap.at(key)-1;
    } else {
        std::cout << "Can't found stock " << code << " for date " << date << std::endl;
        exit(1);
    }
}

long Stock::getOffset(const std::string &date) const{
    if (indexMap2.find(date) != indexMap2.end()) {
        return indexMap2.at(date)-1;
    } else {
        std::cout << "Can't found stock "  << " for date " << date << std::endl;
        exit(1);
    }
}

std::vector<Stock> Stock::readByOffset(long offset)
{
    std::vector<Stock> result;
    std::string name=outputPath+"//output.txt";
    std::ifstream output(name);
    //cout<<offset<<endl;
    if(!output){
        std::cout<<"File Open Error: output.txt"<<std::endl;
        exit(1);
    }
    /*初始化result*/
    output.seekg(offsets[offset]);
    std::string line;
    if(getline(output,line)){
        //cout<<line<<endl;
        Stock temp;
        std::vector<std::string> info;
        std::stringstream ss(line);
        std::string token;
        while(getline(ss,token,','))
            info.push_back(token);
        temp.setInfo(info);
        result.push_back(temp);
    }

    std::string targetCode=result[0].getCode();
    std::string targetDate=result[0].getDate().substr(0,6);
    while(getline(output,line)){
        Stock temp;
        std::vector<std::string> info;
        std::stringstream ss(line);
        std::string token;
        while(getline(ss,token,','))
            info.push_back(token);
        temp.setInfo(info);

        std::string tempDate=temp.getDate();
        tempDate=tempDate.substr(0,6);
        //cout<<temp.getCode()<<" "<<tempDate<<endl;
        //cout<<targetCode<<" "<<targetDate<<endl;
        if(targetCode!=temp.getCode() || targetDate!=tempDate)
            break;
        result.push_back(temp);
    }
    //cout<<result.size()<<endl;
    output.close();
    return result;
}

std::vector<Stock> Stock::readByOffset2(long offset)
{
    std::vector<Stock> result;
    std::string name=outputPath+"//output.txt";
    std::ifstream output(name);
    //cout<<offset<<endl;
    if(!output){
        std::cout<<"File Open Error: output.txt"<<std::endl;
        exit(1);
    }
    /*初始化result*/
    output.seekg(offsets[offset]);
    std::string line;
    if(getline(output,line)){
        //cout<<line<<endl;
        Stock temp;
        std::vector<std::string> info;
        std::stringstream ss(line);
        std::string token;
        while(getline(ss,token,','))
            info.push_back(token);
        temp.setInfo(info);
        result.push_back(temp);
    }

    std::string targetDate=result[0].getDate().substr(0,6);
    while(getline(output,line)){
        //cout<<line<<endl;
        Stock temp;
        std::vector<std::string> info;
        std::stringstream ss(line);
        std::string token;
        while(getline(ss,token,','))
            info.push_back(token);
        temp.setInfo(info);

        std::string tempDate=temp.getDate();
        tempDate=tempDate.substr(0,6);
        //cout<<temp.getCode()<<" "<<tempDate<<endl;
        //cout<<targetCode<<" "<<targetDate<<endl;
        if(targetDate!=tempDate)
            continue;
        result.push_back(temp);
    }
    //cout<<result.size()<<endl;
    output.close();
    return result;
}

std::vector<double> dailyReturn(const std::vector<Stock> &data)
{
    std::vector<double> result;

    for (size_t i = 1; i < data.size(); ++i) {
        double today = stod(data[i].getClose());
        double yesterday = stod(data[i - 1].getClose());

        // 计算隔天收益率
        double dailyReturn = (today - yesterday) / yesterday;
        result.push_back(dailyReturn);
    }

    return result;
}

long Stock::getOffsetByCode(const std::string &code) const
{
    if (indexMap3.find(code) != indexMap3.end()) {
        return indexMap3.at(code)-1;
    } else {
        std::cout << "Can't found stock " << code << std::endl;
        exit(1);
    }
}

std::vector<Stock> Stock::readByOffset3(long offset)
{
    std::vector<Stock> result;
    std::string name=outputPath+"//output.txt";
    std::ifstream output(name);
    //cout<<offset<<endl;
    if(!output){
        std::cout<<"File Open Error: output.txt"<<std::endl;
        exit(1);
    }
    /*初始化result*/
    output.seekg(offsets[offset]);
    std::string line;
    if(getline(output,line)){
        //cout<<line<<endl;
        Stock temp;
        std::vector<std::string> info;
        std::stringstream ss(line);
        std::string token;
        while(getline(ss,token,','))
            info.push_back(token);
        temp.setInfo(info);
        result.push_back(temp);
    }

    std::string targetCode=result[0].getCode();
    while(getline(output,line)){
        Stock temp;
        std::vector<std::string> info;
        std::stringstream ss(line);
        std::string token;
        while(getline(ss,token,','))
            info.push_back(token);
        temp.setInfo(info);

        if(targetCode!=temp.getCode())
            break;
        result.push_back(temp);
    }
    //cout<<result.size()<<endl;
    output.close();
    return result;
}

std::vector<Stock> Stock::readBySize(long offset, int size)
{
    std::vector<Stock> result;
    std::string name=outputPath+"//output.txt";
    std::ifstream output(name);
    //cout<<offset<<endl;
    if(!output){
        std::cout<<"File Open Error: output.txt"<<std::endl;
        exit(1);
    }
    /*初始化result*/
    output.seekg(offsets[offset]);
    std::string line;
    if(getline(output,line)){
        //cout<<line<<endl;
        Stock temp;
        std::vector<std::string> info;
        std::stringstream ss(line);
        std::string token;
        while(getline(ss,token,','))
            info.push_back(token);
        temp.setInfo(info);
        result.push_back(temp);
    }

    int cnt=1;
    std::string targetDate=result[0].getDate().substr(0,6);
    while(getline(output,line)){
        //cout<<line<<endl;
        cnt++;
        if(cnt>size)
            break;
        Stock temp;
        std::vector<std::string> info;
        std::stringstream ss(line);
        std::string token;
        while(getline(ss,token,','))
            info.push_back(token);
        temp.setInfo(info);

        std::string tempDate=temp.getDate();
        tempDate=tempDate.substr(0,6);
        //cout<<temp.getCode()<<" "<<tempDate<<endl;
        //cout<<targetCode<<" "<<targetDate<<endl;
        if(targetDate!=tempDate)
            continue;
        result.push_back(temp);
    }
    //cout<<result.size()<<endl;
    output.close();
    return result;
}
