#include <utility>
#include <unordered_map>
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
    unordered_map<TreeNode* , pair<int,int>>map;
    int sum = 0;
    int averageOfSubtree(TreeNode* root) {
        helper(root);
        return sum;
    }
    pair<int,int> helper(TreeNode* root){
        if(!root) return {0,0};
        pair<int,int> left  = helper(root->left);
        pair<int,int> right = helper(root->right);
        
        int total = root->val + left.first + right.first;
        int count = 1 + left.second + right.second;

        if(total/count == root->val) sum++;
        return {total,count};
    }
};
