#include <iostream>
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
int sum = 0;
    int sumRootToLeaf(TreeNode* root) {
        string s = "";
        helper(root,s);
        return sum;
    }
    void convertToInt(string& s){
        for(int i = 0 ; i < s.size() ; i++)
            if(s[i] == '1') sum += 1 << (s.size()-i-1);
    }
    void helper(TreeNode* root, string& s){
        if(!root) return;
        s.push_back(root->val +'0'); 
       if(!root->left && !root->right) 
            convertToInt(s); 

        helper(root->left,s);
        helper(root->right,s);   

        s.pop_back();
    }
};
