#pragma once
#include<bits/stdc++.h>
using namespace std;
 //点-边结构体
struct VP
{
    int start;
    int end;
    int len;
};


class Kruskal
{
public:
    vector<int> parent; //记录节点的根
    vector<int> rank; //记录根节点的深度（秩优化）
    vector<int> size; //每个连通分量的节点个数
    vector<int> len; //记录每个连通分量的所有边长度
    int num; //记录节点个数
    Kruskal(int n):parent(vector<int>(n)),rank(vector<int>(n)),len(n,0),size(n,1),num(n)
    {
        for(int i=0;i<n;++i)
            parent[i] = i;
    }

    int Find(int index)
    {
        if(index!=parent[index]) parent[index] = Find(parent[index]);
        return parent[index];
    }

    int Union(int index1,int index2,int length)
    {
        int find_1 = Find(index1);
        int find_2 = Find(index2);
        if(find_1!=find_2)
        {
            //让秩小的去连通秩大的，避免增加连接后的长度
            if(rank[find_1]>rank[find_2])
            {
                swap(find_1,find_2);
            }
            parent[find_1] = find_2;
            //修改秩
            if(rank[find_1]==rank[find_2]) ++rank[find_2];//秩相同的话，增加一长度
            //修改合并之后的节点个数，边长度
            size[find_2] += size[find_1];
            len[find_2] += len[find_1]+length;
            //如果某个连通分量的节点数包括了所有节点，直接返回该分量的所有边长度
            if(size[find_2]==num) return len[find_2];
        }
        return -1;
    }
};


class Solution
{
public:
    int minCostConnectPoints(vector<vector<int>>& points)
    {
        int res = 0;
        int n = points.size();
        Kruskal ds(n);
        vector<VP> edges;
        //建立点-边数据结构
        for(int i=0;i<n;++i)
        {
            for(int j=i+1;j<n;++j)
            {
                VP vp = {i,j,abs(points[i][0]-points[j][0])+abs(points[i][1]-points[j][1])};
                edges.emplace_back(vp);
            }
        }
        //按边长排序
        sort(edges.begin(),edges.end(),[](const auto& a,const auto& b)
        {
            return a.len<b.len;
        });

        //连通分量合并
        for(auto&e:edges)
        {
            res = ds.Union(e.start, e.end, e.len);
            if(res!=-1) return res;
        }
        return 0;
    }
};