#include <iostream>
#include <cmath>
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
    bool isBalanced(TreeNode* root) {
    if(!root) return true;
        int l = calcH(root->left);
        int r = calcH(root->right);
        if(abs(l-r) > 1) return false;
        return isBalanced(root->left) &&
               isBalanced(root->right);
    }
    int calcH(TreeNode* root){
       if(!root) return 0;
       int left = calcH(root->left);
       int right = calcH(root->right);
       return 1 + max(left,right);
    }
};
