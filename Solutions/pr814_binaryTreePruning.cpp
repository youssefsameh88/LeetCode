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
    TreeNode* pruneTree(TreeNode* root) {
        if(!root) return nullptr;
        if(helper(root)) return nullptr;
        root->left = pruneTree(root->left);
        root->right = pruneTree(root->right);
        return root;
    }
    bool helper(TreeNode* root){
        if(!root) return true;
        if(root->val == 1) return false;
        return helper(root->left) && helper(root->right);
    }
};
