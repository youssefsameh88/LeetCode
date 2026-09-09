#include <iostream>
#include <vector>
#include <algorithm>
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
    int maxLevel = 0;
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        maxLevel = maxDepth(root) ;
        vector<vector<int>> l(maxLevel, vector<int>(0));
        int level = 0;
        collect(root,level,l);
        for(int i = 1 ; i < l.size() ; i += 2) reverse(l[i].begin(),l[i].end());
        return l;
    }
    void collect(TreeNode* root, int level, vector<vector<int>> &l){
        if(!root) return;
        l[level].push_back(root->val);
        collect(root->left,level+1,l);
        collect(root->right,level+1,l);
    }
    int maxDepth(TreeNode* root) {
       if(!root) return 0;
       int left = 1 + maxDepth(root->left);
       int right = 1 + maxDepth(root->right);

       return max(left, right);
    }
};