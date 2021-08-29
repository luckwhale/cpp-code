#include<bits/stdc++.h> 
using namespace std;
//使用dp的一个例子，完全平方数的和。  
//大问题可以通过状态转移为小问题。
class Solution {
public:
    int numSquares(int n) {
    vector<int> f(n+1);
    f[0] = 0;
    for(int i=1;i<n+1;i++)
    {
       int minn = INT_MAX;
       for(int j=1;j*j<=i;j++)
       {
           minn = min(minn,f[i-j*j]);
       }
       f[i] = minn+1;
    }
    return f[n];
    }
};