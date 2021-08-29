#include <bits/stdc++.h>
using namespace std;
 
void getpre(int *postorder,int *inorder,int n)    //其中数组postorder为后序,inorder为中序,n为每次遍历数目
    //n为后序中根节点的位置加一
{
    if(n>0)  
    { 
        int root = postorder[n-1];  //根结点为后序遍历的最后一个
        //归纳法比较好用
        int i;
        for(i = 0; i < n; i++)    //在中序遍历中查找根结点
        {
            if(inorder[i] == root) 
            {
                break;
            }
        }
        cout << " " << root;
        getpre(postorder, inorder, i);    //对左子树来查找根结点
        getpre(postorder+i, inorder+i+1, n-i-1);  //对右子树来查找根结点
        //为什么是n-i-1？这个其实是把右子树平移了(后和中的都进行了平移)
        //这种方法是尝试着把不能解决的问题转化成可以解决的问题
        //注意数组不要越界
    }
}
 
int main()
{
    int n;
    cin >> n;
    int postorder[n],inorder[n];  //postorder[n]后序 inorder[n]中序
    for(int i=0;i<n;i++)
    {
        cin >> postorder[i];    //输入后序
    }
    for(int i=0;i<n;i++)
    {
        cin >> inorder[i];    //输入中序
    }
    cout << "Preorder:";
    getpre(postorder,inorder,n);
    return 0;
}