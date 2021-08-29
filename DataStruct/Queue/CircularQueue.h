#pragma once
//其实发现哪怕实现方式不同，但是使用方式大致相同
#include <iostream>
using namespace std;
const int QueueSize = 100;
template <class ElemType>
class CircularQueue
{
    public:
    CircularQueue();
    ~CircularQueue();
    void EnQueue(ElemType x);
    ElemType DeQueue();     //出队
    ElemType GetQueue();    //获取将要出队的第一个元素，但不出队   我不支持直接输出队列，我要保证封闭性
    int Length();
    int Empty();
    private:
    ElemType data[QueueSize];
    int front=0,rear=0;  //循环队列不同之处在于指针位置的相对变动  物理位置不是逻辑位置
    //rear指向将要插入的那个位置
    int length=0;
};
template <class ElemType>
CircularQueue<ElemType>::CircularQueue()
{
    cout<<"A CircularQueue has been created!"<<endl;
}

template <class ElemType>
void CircularQueue<ElemType>::EnQueue(ElemType x)
{
    if(length==QueueSize)
       throw "队列已满，参数非法";
    else
        length++;
    data[rear]=x;
    if(rear==QueueSize-1)
    {
        rear=0;
    }
    else
        rear++;
}

template <class ElemType>
ElemType CircularQueue<ElemType>::DeQueue()
{
    //首先都是异常检验
    if(length==0)
       throw "队列为空队列，参数非法";
    else if(front==QueueSize-1)
    {
        front=0;
        return data[QueueSize-1];
    }
    else 
    {
        front++;
        return data[front-1];
    }
       
}
template <class ElemType>
ElemType CircularQueue<ElemType>::GetQueue()
{
    cout<<data[front]<<endl;
}

template<class ElemType>
int CircularQueue<ElemType>::Length()
{
    return length;
}

template <class ElemType>
int CircularQueue<ElemType>::Empty()
{
    if(length==0)
      return 1;
    else 
      return 0;
}

template <class ElemType>
CircularQueue<ElemType>::~CircularQueue()
{
    //delete []data;
    cout<<"The queue has been deleted!"<<endl;
}