#pragma once
#include <iostream>
#include <stack>
using namespace std;
 
#define MaxNode 20
#define MAX 2000
#define StartNode 1
 
int map[MaxNode+1][MaxNode+1];   //这个用的是邻连接矩阵实现的
 
void dfs_stack(int start, int n){
    int visited[MaxNode],s_top;
    for(int i = 0;i <= MaxNode; i++){
        visited[i] = 0;
    }
    visited[start] = 1;
    stack <int> s;
    cout<<start<<" ";
    for(int i = 1; i <= n; i++){
        if(map[i][start] == 1 && !visited[i] ){
            visited[i] =  1;
            s.push(i);
        }
    }
    
    while(!s.empty()){
        s_top =  s.top();
        visited[s_top] = 1;
        cout<<s_top<<" ";
        s.pop();
        for(int i = 1; i <= n; i++){
            if(map[i][s_top] == 1 && !visited[i] ){
                visited[i] = 1;
                s.push(i);
            }
        }
    }
    
}