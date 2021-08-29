#pragma once
//实现要用链表哦，但是要考虑怎么实现
template <class ElemType>
struct Node
{
    Node *next=NULL;
    ElemType x;
};
template <class ElemType>
class LinkedQueue
{
    public:
    LinkedQueue();
    LinkedQueue();
    ~LinkedQueue();
    void EnQueue(ElemType x);
    ElemType DeQueue();
    ElemType GetQueue();
    int Length();
    int Empty();
    private:
    Node* front=NULL,rear=NULL;
    int length=0;
};