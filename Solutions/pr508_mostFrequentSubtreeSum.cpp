#include <vector>
#include <unordered_map>
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
unordered_map<int,int> map;
    vector<int> findFrequentTreeSum(TreeNode* root) {
        helper(root);
        vector<int> v;
        auto Max = max_element(map.begin(), map.end(),
    [](auto &a,auto &b) {return a.second < b.second;});

    for (auto& [key, value] : map) {
    if (value == Max->second) 
        v.push_back(key);
    
}
return v;

    }
    int helper(TreeNode* root){
        if(!root) return 0;
         int sum = root->val + helper(root->left) + helper(root->right);

         if(map.find(sum) != map.end()) map[sum]++;
         else map[sum] = 1;
         return sum;
    }
};
