#include <bits/stdc++.h>
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
    int ans = 0;
    int countDominantNodes(TreeNode* root) {
        helper(root);
        return ans;
    }
    int helper(TreeNode* root){
        if(!root) return 0;
        if(!root->left && !root->right){
            ans++;
            return root->val;
        }
        int a = helper(root->left);
        int b = helper(root->right);
        if(root->val >= a && root->val >= b) ans++;
        return max(a,max(b, root->val));
    }
};
