//也称为优先队列
#include <iostream>
using namespace std;
#define MaxSize 100
class Heap
{
public:
    void Print();  //用来输出到堆顶的路径
    void Insert(); //用来向堆中输入元素
    void Out();    //用来输出堆顶

private: 
    int Array[MaxSize];
    int number = 0;
};