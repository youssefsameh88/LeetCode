#include <vector>
#include <string>
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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<vector<int>> s;
        vector<string> ans;
        vector<int> v;
        helper(root,s,v);
        for(int i = 0 ; i < s.size() ; i++){
            string str = "";
            if(!s[i].empty()){
                 str = to_string(s[i][0]) ;
            for(int j = 1 ; j < s[i].size() ; j++){
            str += "->" + to_string(s[i][j]);
        }
            }
            if(str != "") ans.push_back(str);
        }
        return ans;
    }
    void helper(TreeNode* root, vector<vector<int>>& s, vector<int>& v){
        if(!root) return;
        v.push_back(root->val);
        if(!root->left && !root->right) s.push_back(v);
        else{
            helper(root->left,s,v);
            helper(root->right,s,v);
        }
        v.pop_back();
    }
};
