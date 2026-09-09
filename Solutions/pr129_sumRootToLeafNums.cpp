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
    int sumNumbers(TreeNode* root) {
        int ans = 0, total = 0;
        helper(root, ans, total);
        return ans;
    }
    void helper(TreeNode* root, int& ans, int total){
        if(!root) return;
        total = 10*total + root->val;
        if(!root->left && !root->right){
            ans += total;
            return;
        }
        helper(root->left,ans,total);
        helper(root->right,ans,total);
    }
};