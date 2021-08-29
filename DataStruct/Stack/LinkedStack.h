#pragma once
template <class ElemType>
struct Node
{
    Node *next=NULL;
    ElemType data;
};

template <class ElemType>
class SeqStack
{
   public:
    SeqStack(){};        //构造函数，初始化空栈     有没有必要提供有参构造函数
    ~SeqStack(){};       //析构函数
    void Push(ElemType x);     //元素x入栈
    ElemType Pop();       //返回栈顶元素的值并出栈
    ElemType GetTop();       //返回栈顶元素
    int Empty();        //判断栈是否为空，空则返回1，否则返回0
   private:
    Node* first;    //栈顶指针
    int length=0;      //栈的长度,用于判断栈是否已经空了
};

template <class ElemType>
void SeqStack<ElemType>::Push(ElemType x)
{
    Node * p=NULL;
    p=new Node<ELemType>;
    p->next=first;
    p->data=x;
    length++;
    first=p;
}

template <class ElemType>
ElemType SeqStack<ElemType>::Pop()
{
    if(legnth==0)
     throw "栈为空，操作非法";
   ElemType y=first->data;
   first=first->next;
   length--;
   return y;
}

template <class ElemType>
ElemType SeqStack<ElemType>::GetTop()
{
    if(legnth==0)
     throw "栈为空，操作非法";
    else
     return first->data;
}

template <class ElemType>
int SeqStack<ElemType>::Empty()
{
   return length;
}