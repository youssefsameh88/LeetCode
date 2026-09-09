
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
    void flatten(TreeNode* root) {
         if(!root) return;
         TreeNode* tempR = nullptr;
         if(root->left){
             tempR = root->right;
       root->right = root->left;
        root->left = nullptr;
         }
       flatten(root->right);
       TreeNode* curr =root->right;
       while(curr && curr->right) curr = curr->right;
       if(curr) curr->right = tempR;
       flatten(curr);
    }
};
