#pragma once
//其实发现哪怕实现方式不同，但是使用方式大致相同
//顺序队列有必要吗？
const int QueueSize = 100;
template <class ElemType>
class OrderQueue
{
    public:
    OrderQueue();
    ~OrderQueue();
    void EnQueue(ElemType x);
    ElemType DeQueue();
    ElemType GetQueue();
    int Length();
    int Empty();
    private:
    ElemType data[QueueSize];
    int front,rear;
    int length=0;
};