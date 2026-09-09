#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};


class Solution {
public:
    vector<int> ans;
    vector<int> preorder(Node* root) {
        if(root) ans.push_back(root->val);
        dfs(root);
        return ans;
    }
    void dfs(Node* root){
        if(!root) return;
        for(auto child : root->children){
            ans.push_back(child->val);
            dfs(child);
        }
    }
};
