#ifndef MINHEAP_H
#define MINHEAP_H

#include <vector>
#include "minnode.h"

class minHeap
{
public:
    minHeap();
    void push(MinNode node);
    void pop();
    MinNode top();
    bool empty(){
        return heap.empty();
    }
    void heapUp(int index);
    void heapDown(int index);
    void swap(const int &n1, const int &n2);

private:
    std::vector<MinNode> heap;
};

#endif // MINHEAP_H
