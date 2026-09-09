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
    bool isSymmetric(TreeNode* root) {
        return symmetricCheck(root->left, root->right);
    }
    bool symmetricCheck(TreeNode* left, TreeNode* right){
        if(!left && !right) return true;
        if(!right || !left) return false;
        if(left->val == right->val){
            return symmetricCheck(left->left , right->right) 
            && symmetricCheck(left->right , right->left);
        }
        else return false;
    }
};