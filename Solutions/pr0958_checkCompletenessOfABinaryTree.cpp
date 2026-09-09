#include <vector>
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
vector<TreeNode*> leaves;
    bool isCompleteTree(TreeNode* root) {
        int h = calcH(root);
        bool ch1 = helper(root,h,1), ch2 = true;
        if(!ch1) return false;
        int i = leaves.size() - 1;
        while(i && !leaves[i]) i--;
        while(i && leaves[i]) i--;
        ch2 = leaves[i];
        return ch2;
    }
    int calcH(TreeNode* root){
        if(!root) return 0;
        return 1 + max(calcH(root->left), calcH(root->right));
    }
    bool helper(TreeNode* root, int h, int l){
        if(l == h) leaves.push_back(root);
        if(!root) return l >= h;
        return helper(root->left, h, l+1) && helper(root->right,h,l+1);
    }
};
