#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;
 
typedef int ElementType;
typedef struct AVLNode* Position;
typedef Position AVLTree;
typedef struct AVLNode{
	ElementType Data;
	AVLTree Left;
	AVLTree Right;
};
//计算树高,树高为整体高度
int GetHeight(AVLTree A){
	int HL,HR,MaxH;
	if(A==NULL)
		return 0;
	else{
		HL=GetHeight(A->Left);
		HR=GetHeight(A->Right);
		MaxH=max(HL,HR);
		return (MaxH+1); 
	}
}
//左单旋（顺时针）
AVLTree SingleLeftRotation(AVLTree A){
	AVLTree B=A->Left;
	A->Left=B->Right;
	B->Right=A;
	return B;
}
//右单旋（逆时针）
AVLTree SingleRightRotation(AVLTree A){
	AVLTree B=A->Right;
	A->Right=B->Left;
	B->Left=A;
	return B;
}
//左-右双旋
AVLTree DoubleLeftRightRotation(AVLTree A){
	A->Left=SingleRightRotation(A->Left);
	return SingleLeftRotation(A);
}
//右-左双旋
AVLTree DoubleRightLeftRotation(AVLTree A){
	A->Right=SingleLeftRotation(A->Right);
	return SingleRightRotation(A);
}
 
AVLTree Insert(AVLTree A,ElementType X){
	if(!A){
		A=(AVLTree)malloc(sizeof(struct AVLNode));
		A->Data=X;
		A->Left=A->Right=NULL;
	}
	else if(X<A->Data){
		A->Left=Insert(A->Left,X);
        //A对应的都是三个结点中最高的那一个
		if(GetHeight(A->Left)-GetHeight(A->Right)==2)
			if(X<A->Left->Data)
				A=SingleLeftRotation(A);
			else
				A=DoubleLeftRightRotation(A); 
	}
	else if(X>A->Data){
		A->Right=Insert(A->Right,X);
		if(GetHeight(A->Left)-GetHeight(A->Right)==-2)
			if(X>A->Right->Data)
				A=SingleRightRotation(A);
			else
				A=DoubleRightLeftRotation(A);
	}
	return A;
} 
 