#pragma once
#include <iostream>
#include <stack>
//什么时候适合用面向对象的眼光去解决问题
template <class ElemType>
//模板的机制是什么？？
struct TreeNode
{
	ElemType x;
    TreeNode<ElemType>* left=NULL;
	//为什么需要加上这个括号？
	TreeNode<ElemType>* right=NULL;
};
template <class ElemType>
class BinaryTree
{
    public:
	BinaryTree();
	~BinaryTree();//析构函数到底怎么写？？
	void PrintForword();
	void PrintMidan();
	void PrintBack();
	int BFSTreeSearch(ElemType x);//查找树中有无某个结点，用队列去实现
    int DFSTreeSearch(ElemType x);//用栈去实现
	void LevelPrint(); //逐层遍历
	BinaryTree operator+(const & BinaryTree);
	void FindHeight();   //找到书的高度
	void IfSame();  //判读两颗树是否同构
	//想把原来的对象删掉，防止占用内存怎么办？？
	private:
	TreeNode<ElemType>*first=NULL;
	int number=0;   //记录结点的个数
};
