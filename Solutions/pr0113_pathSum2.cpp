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
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> v;
        Sum(root, targetSum, ans,v);
        return ans;
    }
    void Sum(TreeNode* root, int targetSum, vector<vector<int>>& bowl,vector<int> v ) {
        if(!root)return;
        v.push_back(root->val);

        if(!root->left && !root->right ){
            if(targetSum == root->val) bowl.push_back(v);
            v.pop_back();
            return;
        }
        Sum(root->left, targetSum - root->val, bowl, v);
        Sum(root->right, targetSum - root->val, bowl, v);
        v.pop_back();
    }
};