#pragma once
#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class traversal
{
private:
    TreeNode* root;
public:
    vector<int> preorderTraversal() {
        vector<int> answer;
        if(root==nullptr)
        return answer;
        findPreorderTraversal(answer,root);
        return answer;

    }
    void findPreorderTraversal(vector<int>& answer,TreeNode* root)
    {
        //root
        answer.push_back(root->val);
        //left
        if(root->left!=nullptr)
        {
            findPreorderTraversal(answer,root->left);
        }
        //right
        if(root->right!=nullptr)
        {
            findPreorderTraversal(answer,root->right);
        }
        
    }
    //层序遍历
    public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector <vector <int>> ret;
        if (!root) {
            return ret;
        }

        queue <TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int currentLevelSize = q.size();
            ret.push_back(vector <int> ());
            for (int i = 1; i <= currentLevelSize; ++i) {
                auto node = q.front(); q.pop();
                ret.back().push_back(node->val);
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
        }
        
        return ret;
    }
};
class Solution {

};
