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
int dep = 0, num = 0;
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth == 1){
            return new TreeNode(val,root,nullptr);
        }
        dep = depth;
        num = val;
        helper(root, 2);
        return root;
    }
    void helper(TreeNode* root, int level){
        if(!root) return ;
        if(level == dep){
            TreeNode* temp1 = new TreeNode(num);
            TreeNode* temp2 = new TreeNode(num);
            if(root->left) temp1->left = root->left;
            if(root->right) temp2->right = root->right;
            root->left = temp1;
            root->right = temp2;
            return;
        }
        helper(root->left, level+1);
        helper(root->right, level+1);
    }
};
