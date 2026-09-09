#include <iostream>
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
int sum = 0;
int maxHeight = 0;
    int deepestLeavesSum(TreeNode* root) {
        maxHeight = calcH(root);
       helper(root, 1); 
       return sum;
    }
    int calcH(TreeNode* root){
        if(!root) return 0;
        int l = 1 + calcH(root->left);
        int r = 1 + calcH(root->right);
        return max(l, r);
    }
    void helper(TreeNode* root,int height){
        if(!root) return;
        helper(root->left,height+1);
        helper(root->right,height+1);
        if(!root->left && !root->right && height == maxHeight)
            sum += root->val;
    }
};
