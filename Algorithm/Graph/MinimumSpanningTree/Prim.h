#pragma once
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int Prim(vector<vector<int>> &points,int start)
    {
        unsigned INI_MAX = -1;
        int n=points.size();
        int res = 0;
        //1.将points转化成临界矩阵
        vector<vector<int>> g(n,vector<int>(n));//创建二维动态数组
        for(int i=0;i<n;++i)
        {
            //计算的是当前点与其之后的所有点的距离，构成一个上三角，因此必须同时进行两次赋值，这样才能构成完整的矩阵
            for(int j=i+1;j<n;++j)
            {
                int dist = abs(points[i][0]-points[j][0])+abs(points[i][1]-points[j][1]);
                g[i][j] = dist;
                g[j][i] = dist;
            }
        }
        //记录V[i]到Vnew的最近距离
        vector<int> lowcast(n,INI_MAX);
        //记录V[i]是否加入到了Vnew
        vector<int> v(n,-1);

        //2.先将start加入得到Vnew
        v[start] = 0;
        for(int i=0;i<n;++i)
        {
            if(i==start) continue;
            lowcast[i] = g[i][start];
        }

        //3.剩余n-1个节点未加入到Vnew,遍历
        for(int i=1;i<n;++i)
        {
            //找出此时V中，离Vnew最近的点
            int minIdx = -1;
            unsigned minVal = INI_MAX;
            for(int j=0;j<n;++j)
            {
                if(v[j]==0) continue;
                if(lowcast[j]<minVal)
                {
                    minIdx = j;
                    minVal = lowcast[j];
                }
            }
            //跟新当前最小和，该点的标记，该点的距离
            res += minVal;
            v[minIdx] = 0;
            lowcast[minIdx] = -1;

            //跟新lowcast中的最小距离
            for(int j=0;j<n;++j)
            {
                if(v[j]==-1&&g[j][minIdx]<lowcast[j])
                    lowcast[j] = g[j][minIdx];
            }
        }
        return res;
    }
    int minCostConnectPoints(vector<vector<int>>& points) {
        return Prim(points,0);
    }
};