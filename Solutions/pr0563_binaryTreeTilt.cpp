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
    int findTilt(TreeNode* root) {
        tilt(root);
         return sum(root);
    }
    int sum(TreeNode* root){
        if(!root) return 0;
        return root->val + sum(root->left) + sum(root->right);
    }
    void tilt(TreeNode* root){
        if(!root) return;
        root->val = abs(sum(root->left) - sum(root->right));
        tilt(root->left);
        tilt(root->right);
    }
};
