#pragma once
#include <iostream>
using namespace std;
//define
#define ERROR -1   //这种方法也有问题，define并未指定数据类型
#define OK 1
/**借鉴一下别人的写法
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
template <class ElemType> //这种方法可以吗
struct Node
{
    ElemType data;           //是否应该初始化
    Node<ElemType> *next = NULL; //什么时候需要加上<>呢  初始化为NULL是不是更好
};                               //需要这个东西吗
template <class ElemType>
class LinkList
{
public:
    LinkList();                     //建立一个只有头结点的空链表    不含参的构造函数调用的时候不要带括号
    LinkList(ElemType a[], int n);  //以数组a为初始数据，建立一个单链表
    ~LinkList();                    //析构函数   怎么设计
    int Length();                   //返回单链表的长度
    ElemType Get(int i);            //按位查找，返回值
    int Locate(ElemType x);         //按值查找，返回位置
    void Insert(int i, ElemType x); //插入x成为第i个元素
    void Erase(int i);             //删除第i个元素
    void PrintList();               //遍历打印整个表
    bool Empty();
    void Reverse();

private:
    Node<ElemType> *first; //头指针
    int length = 0;        //链表的长度
};

template <class ElemType>
LinkList<ElemType>::LinkList(ElemType a[], int n)
{
    Node<ElemType> *Fir = NULL; //注意不要写成野指针了
    Fir = new Node<ElemType>;   //返回的是不是指针       如果new失败了怎么办呢
    if(Fir==NULL)
    throw "fail to ask space";
    first = Fir;                //命名要注意什么？
    length = n;
    for (int i = 0; i < n; i++)
    {
        Node<ElemType> *Next = NULL;
        Next = new Node<ElemType>; //什么东西首字母要大写
        Fir->data = a[i];
        Fir->next = Next; //干完了可以覆盖了
        Fir = Next;
    } //构造函数不能返回任何值
}

template <class ElemType>
LinkList<ElemType>::LinkList()
{
    Node<ElemType> *Fir = NULL; //注意不要写成野指针了
    Fir = new Node<ElemType>;
    first = Fir;
}

template <class ElemType>
int LinkList<ElemType>::Length()
{
    return length;
}

template <class ElemType>
int LinkList<ElemType>::Locate(ElemType x)
{
    int len = 1;
    Node<ElemType> *Fir = first;
    while (Fir->data != x)
    {
        if (len == length)
        {
            throw "没有这个元素";
            return -1;
        }
        Fir = Fir->next;
        len++;
    }
    return len;
}

template <class ElemType>
ElemType LinkList<ElemType>::Get(int i)
{
    if (i < 1 || i > length)
        throw "参数非法";
    Node<ElemType> *Fir = first;
    for (int j = 2; j <= i; j++) //first 这种东西真么把它弄清楚  了解目的
    {
        Fir = Fir->next;
    }
    ElemType x = Fir->data;
    return x;
}

template <class ElemType>
void LinkList<ElemType>::Insert(int i, ElemType x)
{
    if (i < 1 || i > length+1) //只能插入不许追加   该不该允许追加，不应该因为操作者使用时还需要先get到位置比较麻烦
        throw "invalid input";
    length++;
    Node<ElemType> *Fir = first;
    Node<ElemType> *now = NULL;
    now = new Node<ElemType>;
    now->data = x;
    if (i == 1) //第一个的特殊性,需要改变first
    {
        Node<ElemType> *fina = NULL;
        cout<<fina<<endl;
        now->next = first;
        first = now;
        return;
    }
    for (int j = 2; j <= i - 1; j++) //带入特例法
    {
        Fir = Fir->next;
    }
    now->next = Fir->next;
    Fir->next = now;
    return;
}

template <class ElemType>
void LinkList<ElemType>::Erase(int i)
{
    if (i < 1 || i > length)
        throw "invalid input"; //如果throw发现错误了怎么办？ 捕捉到错误后，后面的代码便不再执行
    Node<ElemType> *now = first;
    Node<ElemType> *wait_del = NULL;
    if (i == 1)
    {
        if (first->next == NULL)
        {
            first->data = 0; //按归零进行处理
            length = 0;
        }
        else
        {
            first = first->next; //是否要将原来的指针删除？
            length--;
            delete now; //这个删除机制是什么？
        }
        return;
    }
    int a = 1;
    while (++a != i) //now为待删除的前一个
    {
        now = now->next;
    }
    wait_del = now->next;
    now = wait_del->next;
    length--;
    delete wait_del; //删除指针还是删除指针所指的对象   对象无法访问是不是代表对象已经被删除了
    now->next = NULL;
    return;
}

template <class ElemType>
void LinkList<ElemType>::PrintList()
{
    Node<ElemType> *now = first;
    int a = 1;
    while (a++ <= length)
    {
        cout << now->data << endl;
        now = now->next;
    }
    return;
}

template <class ElemType>
bool LinkList<ElemType>::Empty()
{
    if (length == 0)
        return true;
    else
        return false;
}

template <class ElemType>
void LinkList<ElemType>::Reverse()
{
    if (!length)
       throw "invalid  input!";
    if(length==1)
       return;
    Node<ElemType> *now=first, *late =nullptr, *next = nullptr;
    for(int i=0;i<length-1;i++)
    {
       next = now->next;
       now->next = late;
       late = now;
       now = next;
    }
    now->next = late;
    first = now;
    return ;

}

template <class ElemType>
LinkList<ElemType>::~LinkList()
{
    Node<ElemType> *p = NULL;
    while (first != NULL)
    {
        p = first;
        first = first->next;
        delete p;
    }
}
