#include <vector>
#include <unordered_set>
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
vector<TreeNode*> d;
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        unordered_set<int> set(to_delete.begin(),to_delete.end());
        if(set.find(root->val) == set.end())d.push_back(root);
        helper(root, set);
        return d;
    }
    TreeNode* helper(TreeNode* root, unordered_set<int>& set){
        if(!root) return nullptr;
        root->left = helper(root->left, set);
        root->right = helper(root->right, set);
        if(set.find(root->val) != set.end()){
            if(root->left) d.push_back(root->left);
            if(root->right) d.push_back(root->right);
            helper(root->left,set);
            helper(root->right,set);
            return nullptr;
        }
        return root;
    }
};
