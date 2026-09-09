#include <vector>
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
int maxDepth = 0;
    vector<int> largestValues(TreeNode* root) {
        maxDepth = calcH(root);
    vector<int> levels(maxDepth,INT_MIN);
    helper(root,0,levels);
    return levels;    
    }
    void helper(TreeNode* root, int level,vector<int>& levels){
        if(!root) return;
        levels[level] = max(root->val,levels[level]);
        helper(root->left,level+1,levels);
        helper(root->right,level+1,levels);
    }
    
    int calcH(TreeNode* root){
        if(!root) return 0;
        return max(1+calcH(root->left),1+calcH(root->right));
    }
};