#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};


class Solution {
public:
    //前一个Node是被拷贝对象，后一个是拷贝对象
    unordered_map<Node*, Node*> visited;
    Node* cloneGraph(Node* node) {
        if (node == nullptr) {
            return node;
        }

        // 如果该节点已经被访问过了，则直接从哈希表中取出对应的克隆节点返回
        //visited.find(node)返回一个iterator,visited.end()返回一个空iterator
        //visited.find(node) == visited.end() 代表没有找到
        if (visited.find(node) != visited.end()) {
            return visited[node];
        }

        // 克隆节点，注意到为了深拷贝我们不会克隆它的邻居的列表
        //深拷贝和浅拷贝最大的区别是，浅拷贝只是复制值，对于指针直接复制，导致对象间没有完全分离。
        Node* cloneNode = new Node(node->val);
        // 哈希表存储
        visited[node] = cloneNode;

        // 遍历该节点的邻居并更新克隆节点的邻居列表
        //auto
        for (auto& neighbor: node->neighbors) {
            cloneNode->neighbors.emplace_back(cloneGraph(neighbor));
        }
        return cloneNode;
    }
};
