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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return helper(nums, 0, nums.size()-1);
    }
    TreeNode* helper(vector<int>& nums, int left, int right){
        if(left > right) return nullptr;
        int maxIdx = left;
        for(int i = left ; i <= right; i++)
            if(nums[i] > nums[maxIdx]) maxIdx = i;
        
        TreeNode* node = new TreeNode(nums[maxIdx]);
        node->left = helper(nums, left,maxIdx - 1);
        node->right = helper(nums, maxIdx + 1, right);
        return node;
    }
};
