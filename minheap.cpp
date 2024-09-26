#include "minheap.h"
#include "minnode.h"

minHeap::minHeap()
{

}

void minHeap::pop()
{
    if(!empty()){
        heap[0]=heap.back();
        heap.pop_back();
        heapDown(0);
    }
}

MinNode minHeap::top()
{
    return heap[0];
}

void minHeap::push(MinNode node){
    heap.push_back(node);
    int index=heap.size()-1;
    heapUp(index);
}

void minHeap::heapUp(int index){
    int parent=(index-1)/2;
    while(index!=0 && heap[index]<heap[parent]){
        swap(index, parent);
        index=parent;
        parent=(index-1)/2;
    }
}

void minHeap::heapDown(int index){
    int left=index*2+1;
    int right=index*2+2;
    int min=index;

    if(left<heap.size() && heap[left]<heap[min]){
        min=left;
    }

    if(right<heap.size() && heap[right]<heap[min]){
        min=right;
    }

    if(min!=index){
        swap(index, min);
        heapDown(min);
    }
}

void minHeap::swap(const int &n1, const int &n2)
{
    MinNode temp=heap[n1];
    heap[n1]=heap[n2];
    heap[n2]=temp;
}


