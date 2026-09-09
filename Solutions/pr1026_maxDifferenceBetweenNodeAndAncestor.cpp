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
int maxDiff = 0;
    int maxAncestorDiff(TreeNode* root) {
        vector<int> nums;
        helper(root,nums);
        return maxDiff;
    }
    void helper(TreeNode* root,vector<int>& nums){
        if(!root) return;
        nums.push_back(root->val);
            int maxNum = 0;
            int minNum = nums[0];
        if(!root->left && !root->right){
            for(int i = 0 ; i < nums.size() ; i++){
                if(nums[i] > maxNum) maxNum = nums[i];
                else if(nums[i] < minNum) minNum = nums[i];
            }
            maxDiff = max(maxDiff , maxNum - minNum);
        }
        helper(root->left,nums);
        helper(root->right,nums);
        nums.pop_back();
    }
};
