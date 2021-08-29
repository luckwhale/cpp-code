#pragma once
#include <iostream>
#include <string.h>
using namespace std ;
//为什么要用一个类实现这个东西？？？   系统开销会不会太大
class HuffmanTreeNode{
	public:
		int weight ;
		int parent;
		int left;
		int right;
		void HuffmanTree(HuffmanTreeNode tree[] , int w[] ,int n);
		void select(HuffmanTreeNode tree[],int k,int &i1,int &i2);
		void HuffmanCode(HuffmanTreeNode tree[],string huffmanCode[],int n);
};
void HuffmanTreeNode::HuffmanTree(HuffmanTreeNode tree[] , int w[] ,int n){
	int i1 = 0;
	int i2 = 0; 
	//初始化结点为-1
	for(int i=0;i<2*n-1;i++){
		tree[i].parent = -1;
		tree[i].left = -1;
		tree[i].right = -1;
	} 
	//初始化前n个结点的权值
	for(int i=0;i<n;i++){
		tree[i].weight = w[i];
	} 
	//开始构建哈夫曼树
	for(int k = n ; k<2*n-1;k++){
		//首先找到parent==-1的最小和次小的结点

		select(tree,k,i1,i2);
		tree[k].weight = tree[i1].weight+tree[i2].weight;
		tree[i1].parent = k;
		tree[i2].parent = k;
		tree[k].left = i1;
		tree[k].right = i2; 
	} 
}
void HuffmanTreeNode::select(HuffmanTreeNode tree[],int k,int &i1,int &i2){
	i1 = 0;
	i2 = 0;
	int temp = 1000;
	for(int i = 0;i<k;i++){
		if(temp>tree[i].weight&&tree[i].parent==-1)
			temp = tree[i].weight;
			i1 = i ;
	}
	temp = 1000;
	for(int i = 0;i<k;i++){
		if(temp>tree[i].weight&&tree[i].parent==-1&&i!=i1){
			temp = tree[i].weight;
			i2 = i;
		}
	}
}

void HuffmanTreeNode::HuffmanCode(HuffmanTreeNode tree[] , string huffmanCode[],int n){
	//设置一个临时存储空间
	int cur; 
	int parent; 
	int start;
	//遍历哈夫曼树，生成哈夫曼编码
	for(int i=0;i<n;i++){
		cur = i ;//记录当前处理位置
		parent = tree[i].parent;//找到当前结点的父节点
		while(parent!=-1){//父节点不等于-1指的就是当前
			if(tree[parent].left==cur)
				huffmanCode[i] = '0' + huffmanCode[i];//当前为左子树则编码0
			else
				huffmanCode[i] = '1' + huffmanCode[i];
			
		//改变当前结点与父节点位置向上上搜索 
		cur = parent;
		parent = tree[parent].parent; 
		} 

	}
}