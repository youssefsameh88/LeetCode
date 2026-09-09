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
int H = 0;
    vector<double> averageOfLevels(TreeNode* root) {
        H = calcH(root);
        vector<vector<int>> v(H, vector<int>(0));
        collect(root,0,v);
        vector<double> ans(H, 0);
        int i = 0;
        while(i < H){
            for(int num : v[i]) ans[i] += num;
            ans[i] /= v[i].size();
            i++;
        }
        return ans;
    }
    int calcH(TreeNode* root){
        if(!root) return 0;
        return 1 + max(calcH(root->left), calcH(root->right));
    }
    void collect(TreeNode* root, int level, vector<vector<int>>& v){
        if(!root) return;
        v[level].push_back(root->val);
        collect(root->left,level+1, v);
        collect(root->right,level+1, v);
    }
};
