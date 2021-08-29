#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

typedef int ElementType;
typedef struct AVLNode *AVLTree;
//有无必要要这个typedef
struct AVLNode
{
    ElementType X;
    AVLTree Left;
    AVLTree Right;
};

int GetHeight(AVLTree A)
{
    int Height;
    int Left;
    int Right;
    if (A == NULL)
    {
        return 0;
    }
    else
    {
        Left = GetHeight(A->Left);
        Right = GetHeight(A->Right);
        Height = max(Left, Right);
        return Height + 1;
    }
}

//LL
AVLTree SingleLeftRotation(AVLTree A)
{
    //补充：这个返回的是相当于A的结点
    AVLTree B = A->Left;
    A->Left = B->Right;
    B->Right = A;
    return B;
}

//RR
AVLTree SingleRightRotation(AVLTree A)
{
    AVLTree B = A->Right;
    A->Right = B->Left;
    B->Left = A;
    return B;
}

//LR
AVLTree DoubleLeftRightRotation(AVLTree A)
{
    A->Left = SingleRightRotation(A->Left);
    return SingleLeftRotation(A);
}

//RL
AVLTree DoubleRightLeftRotation(AVLTree A)
{
    A->Right = SingleLeftRotation(A->Right);
    return SingleRightRotation(A);
}

AVLTree Insert(AVLTree A, ElementType X)
{
    if (!A)
    {
        A = (AVLTree)malloc(sizeof(struct AVLNode));
        A->X = X;
        A->Left = NULL;
        A->Right = NULL;
    }
    else if (X < A->X)
    {
        A->Left = Insert(A->Left, X);
        if (GetHeight(A->Left) - GetHeight(A->Right) == 2)
            if (X < A->Left->X)
                A = SingleLeftRotation(A);
            else
                A = DoubleLeftRightRotation(A);
    }
    else if (X > A->X)
    {
        A->Right = Insert(A->Right, X);
        if (GetHeight(A->Left) - GetHeight(A->Right) == -2)
            if (X > A->Right->X)
                A = SingleRightRotation(A);
            else
                A = DoubleRightLeftRotation(A);
    }
    return A;
}