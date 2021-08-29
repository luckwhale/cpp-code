#include <iostream>
#include <queue>
#include <stack>
using namespace std;

struct node
{
    node *a[10] = {NULL};
    //使用辅助整数实现记录是否被找到了
    int d=1;
};

void BFS(node *ancestor)
{
    //定义循环出口
    while (ancestor)
    {
        node *now = ancestor;
        //是否能够使用这个初始化{} 不能这个是拷贝用的
        queue<node *> nodes;
        nodes.push(now);
        for (int i = 0; i < 10; i++)
        {
            if (now->a[i] != NULL)
            {
                nodes.push(now->a[i]);
            }
            else
                return;
        }
        nodes.pop();
        now = nodes.front();
    }

    void DFS(const node *&ancestor)
    {
        stack<node *> nodes;
        nodes.push(ancestor);
        ancestor->d=0;
        while (!nodes.empty())
        {
            //需要具体指向用那一个？
            
                if (now->a[i] != NULL)
                {
                    nodes.push(now->a[i]);
                }
                else()
                    nodes.pop();
            
        }
    }
}