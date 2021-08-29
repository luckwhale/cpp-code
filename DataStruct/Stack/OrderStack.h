#pragma once
const int StackSize = 100;
template <class ElemType>
class SeqStack
{
   public:
    SeqStack();        //构造函数，初始化空栈
    ~SeqStack();       //析构函数
    void Push(ElemType x);     //元素x入栈
    ElemType Pop();       //返回栈顶元素的值并出栈
    ElemType GetTop();       //返回栈顶元素
    int Empty();        //判断栈是否为空，空则返回1，否则返回0
   private:
    ElemType data[StackSize];     //存放栈元素的数组
    int top;                      //栈顶"指针"
};

template <class ElemType>
SeqStack<ElemType>::SeqStack()
{
    top=-1;
}

template <class ElemType>
void SeqStack<ElemType>::Push(ElemType x)
{
    if (top==StackSize-1)
      throw "参数非法";
    else
    {
        data[++top]=x;
    }
}

template <class ElemType>
ElemType SeqStack<ElemType>::Pop()
{
    if (top==-1)
     throw"栈为空，操作非法";
    return data[top--];
}

template <class ElemType>
ElemType SeqStack<ElemType>::GetTop()
{
    if (top==-1)
     throw"栈为空，操作非法";
    return data[top];
}

template <class ElemType>
int SeqStack<ElemType>::Empty()
{
    if (top==-1)
      return 1;
    else
      return 0;
}