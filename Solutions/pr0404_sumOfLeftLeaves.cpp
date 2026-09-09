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
    int sumOfLeftLeaves(TreeNode* root) {
        if(!root) return 0;
        TreeNode* l = root->left;
            int left = (l && !l->left && !l->right) ? l->val : 0;
            return left + sumOfLeftLeaves(root->right)+
            sumOfLeftLeaves(root->left);
    }
};
