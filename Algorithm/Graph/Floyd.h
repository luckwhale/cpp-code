#pragma once
#include <iostream>
#include <cstdio>
#define INT_MAX 0x7fffffff
using namespace std;
const int maxn=101;     //点个数
int map[maxn][maxn];    //邻接矩阵
int pre[maxn][maxn];    //pre[2][3]存储最短路径3的前一个点是2
int dist[maxn][maxn];
int n;
void floyd()
{
    int i,j,k;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            dist[i][j]=map[i][j];
            pre[i][j]=i;
        }
    }
    for(k=1;k<=n;k++)
    {
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=n;j++)
            {
                if(dist[i][k]!=INT_MAX&&dist[k][j]!=INT_MAX&&dist[i][k]+dist[k][j]<dist[i][j])
                {
                    dist[i][j]=dist[i][k]+dist[k][j];
                    pre[i][j]=pre[k][j];
                }
            }
        }
    }
}
int main()
{
    freopen("IN.TXT","r",stdin);
    scanf("%d",&n);
    int from,to,w;
    int i,j;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
            map[i][j]=INT_MAX;
    }
    for(i=1;i<=n;i++)
    map[i][i]=0;
    while(scanf("%d%d%d",&from,&to,&w)!=EOF)
    {
        if(from==0)
        break;
        map[from][to]=w;
        map[to][from]=w;
    }
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
            printf("%d  ",map[i][j]);
        printf("\n");
    }
    printf("Floyd:\n");
    floyd();
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
            printf("%d  ",dist[i][j]);
        printf("\n");
    }
    cout << "Hello world!" << endl;
    return 0;
}