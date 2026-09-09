#include <iostream>
#include <vector>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector <TreeNode*> pPath;
        vector <TreeNode*> qPath;
        collect(root, p, pPath);
        collect(root, q, qPath);
        int m = min(pPath.size() , qPath.size());
        int i = 0;
        while(i < m && pPath[i]->val == qPath[i]->val) i++;

        return pPath[i-1]; 
    }

    bool collect(TreeNode* root, TreeNode* p , vector<TreeNode*>& v){
        if(!root ) return false;
        v.push_back(root);
        if(root == p) return true;

        if(collect(root->left, p, v) || collect(root->right, p, v)) return true;

        v.pop_back();
        return false;
    }
};