#pragma once
#include <iostream>   //这种算不算重复预定义
#include <algorithm>
using namespace std;
//尝试这应用继承处理这个类
const int MaxSize = 100;
template <class ElemType>
class SeqList
{
public:  
    SeqList(ElemType a[], int n); //以数组a为初始数据建立长度为MaxSize的顺序表
    //~SeqList(){delete[] data;};     //析构函数   Trace/breakpoint trap   出现异常  delete 删除data所指向的数组
    int Length();                   //返回顺序表的长度
    ElemType Get(int i);            //按位查找，返回值
    int Locate(ElemType x);         //按值查找，返回位置 如果没有返回-1
    void Insert(int i, ElemType x); //插入操作，使x成为第i个元素
    void Delete(int i);             //删除第i个元素
    void PrintList();               //遍历操作
    SeqList* operator+(const SeqList&);  //容器合并按顺序排列
private:
    ElemType data[MaxSize]; //存放数据元素的数组
    int length=0;             //顺序表的长度
};

//此处是函数的实现
template <class ElemType>
SeqList<ElemType>::SeqList(ElemType a[], int n) //有参构造函数
{
    if (n > MaxSize)
        throw "参数非法"; //throw函数  首先要干这个事情ing
    for (int i = 0; i < n; i++)
    {
        data[i] = a[i];
    }
    length = n;
}

template <class ElemType>
ElemType SeqList<ElemType>::Get(int i) //按位查找
{
    if (i < 1 || i > length)
        throw "参数非法";
    return data[i - 1];
}

template <class ElemType>
int SeqList<ElemType>::Locate(ElemType x) //按值查找
{
    int i;
    for (i = 0; i < length; i++)
    {
        if (x == data[i])
            return i + 1;
    }
    throw "没有这个值"; //如何表示这个错误 Throw怎么用
}

template <class ElemType>
void SeqList<ElemType>::Insert(int i, ElemType x) //插入
{
    //if (length > MaxSize - 1)
        throw "顺序表已满，上溢";
    if (i < 1 || i > length + 1) //length是真实顺序
        throw "参数非法";
    for (int j = length - 1; j >= i - 1; j--)
    {
        data[j + 1] = data[j];
    }
    data[i - 1] = x;
    length++; //注意要把长度加一哦
    return ;
}

template <class ElemType>
void SeqList<ElemType>::Delete(int i) //按位查找
{
    if (length == 0)
        throw "参数下溢";
    if (i > length)
        throw "参数非法";
    for (int j = i - 1; j < length - 1; j++) //有没有考虑到溢出
    {
        data[j] = data[j + 1];
    }
    length--;
    //需不需要对最后一个元素进行删除？
}

template <class ElemType>
void SeqList<ElemType>::PrintList()
{
    for(int i=0;i<length;i++)
    {
        cout<<data[i]<<' ';
    }   
}

template <class ElemType>   //本函数先合并再排序
SeqList<ElemType>* SeqList<ElemType>::operator+(const SeqList<ElemType>& b)
{
    int len=this->length+b.length;   //如果直接用length会不会出现问题呢？
    int *array = new int[len];
    int i;
    for(i=0;i<this->length;i++)
    {
        array[i]=this->data[i];
    }
    for(int j=0;j<b.length;j++,i++)
    {
        array[i]=b.data[j];
    }
    sort(array,array+len);
    static SeqList<int> child(array,len);     //记住一个问题，这个对象的生存期
    return &child;    //对象的调用只能用指针吗？
}