#pragma once
//其实发现哪怕实现方式不同，但是使用方式大致相同
//iostream有没有必要加入
//双向链表使用顺序表还是链表？
const int QueueSize = 100;
template <class ElemType>
class Deque
{
    public:
    Deque();
    ~Deque();
    void EnQueue(ElemType x,int i);   //仅支持一个进入，和以数列的形式进入相比怎么样？
    ElemType DeQueue(int i);
    ElemType GetQueue(int i);
    int Length();
    int Empty();
    void Print();  //这个东西是否违反了封装的要求？
    private:
    ElemType data[QueueSize];
    int front,rear;
};
