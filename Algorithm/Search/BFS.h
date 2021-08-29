#pragma once
#include<iostream>
#include<vector>
#include<queue>
#include<memory.h>
 
using namespace std;
 
vector<vector<int>> tree;//声明一个二维向量
int flag[10];//用于搜索到了节点i的第几个节点
queue<int> M;//声明一个队列
int ar_tree[8] = { 1,1,1,3,5,3,5,7 };
void BFS(int node) {
	int temp;
	cout << node << " ";
	//从队列中取出第一个节点
	int m_first = M.front();
	M.pop();
	while(flag[node] < tree[node].size()) {
		temp = tree[node][flag[node]];
		flag[node]++;
		//把temp加入队列中
		M.push(temp);
	}
	if (!M.empty()) {
		BFS(M.front());
	}
}
