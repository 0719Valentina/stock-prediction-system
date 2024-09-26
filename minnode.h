#ifndef MINNODE_H
#define MINNODE_H

#include "stock.h"

class MinNode
{
public:
    Stock element;
    int index;/*属于哪个分文件*/

    MinNode(const Stock& e, int i):element(e),index(i){}

    //最小堆
    bool operator<(const MinNode& other) const {
        /*先比较股票代码*/
        if(element.getCode() != other.element.getCode()){
            return element.getCode() < other.element.getCode();
        }
        else{/*再比较交易日期*/
            return element.getDate() < other.element.getDate();
        }
    }
};

//typedef std::priority_queue<MinNode, std::vector<MinNode>> minHeap;

#endif // MINNODE_H
