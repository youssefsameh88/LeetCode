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
int num = 0;
int maxLevel = 0;
    int findBottomLeftValue(TreeNode* root) {
        helper(root,1);
        return num;
    }
    void helper(TreeNode* root, int level){
        if(!root) return ;
        if(level > maxLevel ){
            num = root->val;
            maxLevel = level;
        }
        helper(root->left, level+1);
        helper(root->right, level+1);
    }
};
