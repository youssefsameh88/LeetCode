#include <iostream>
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
    int maxLevel = 0;
    bool isEvenOddTree(TreeNode* root) {
        if((root->val)%2 == 0) return false;
        maxLevel = calcH(root);
        int level = 0;
        vector<vector<int>> v(maxLevel);
        collect(root,level,v);
        for(int i = 1; i < v.size(); i++){
            if(v[i].size() == 1){
                if(!(i%2 ^ v[i][0]%2)) return false;
            }
        for(int j = 0; j < v[i].size() - 1; j++){
            if(i%2){
                if(v[i][j] <= v[i][j+1]) return false;
                if(v[i][j]%2 == 1 || v[i][j+1]%2 == 1) return false;
            }
            else {
                if(v[i][j] >= v[i][j+1] || !(v[i][j]%2) || !(v[i][j+1]%2)) return false;
                if(v[i][j]%2 == 0 || v[i][j+1]%2 == 0) return false;
            }
         }
        }
        return true;
    }
    int calcH(TreeNode* root){
        if(!root) return 0;
        int left = 1 + calcH(root->left);
        int right = 1 + calcH(root->right);
        return max(left,right);
    }
    void collect(TreeNode* root, int level, vector<vector<int>>& v){
        if(!root) return;
        v[level].push_back(root->val);
        collect(root->left,level+1,v);
        collect(root->right,level+1,v);
    }
};
