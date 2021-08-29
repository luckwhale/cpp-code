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
    int top1,top2;                      //栈顶"指针"
};

