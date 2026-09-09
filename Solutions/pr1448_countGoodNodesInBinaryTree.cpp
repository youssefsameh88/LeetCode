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
    int total = 1;
    int goodNodes(TreeNode* root) {
        helper(root->left,root->val);
        helper(root->right,root->val);
        return total;
    }
    void helper(TreeNode* root, int maxNum){
        if(!root) return;
        if(root->val > maxNum) maxNum = root->val;
        helper(root->left,maxNum);
        helper(root->right,maxNum);
        if(maxNum <= root->val) total++;
    }
};
