#include <iostream>
#include <vector>
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
    int minCol = 1001;
    int maxCol = -1001;
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> m;
        int r = 0, c = 0;
        helper(root,m,r,c);
        sort(m.begin(), m.end(), [](vector<int>& a, vector<int>& b) {
    if (a[1] != b[1]) return a[1] < b[1];
    if (a[0] != b[0]) return a[0] < b[0]; 
    return a[2] < b[2];                   
});
       
        vector<vector<int>> ans;

        for(int i = minCol ; i <= maxCol ; i++){
            ans.push_back({});
        for(int j = 0 ; j < m.size() ; j++){
            if(m[j][1] == i) {
                ans[i - minCol].push_back(m[j][2]);
            }
         }
        }
        
        return ans;
    }

    void helper(TreeNode* root,vector<vector<int>>& v, int row, int column){
        if(!root) return;
        minCol = min(minCol, column);
        maxCol = max(maxCol, column);
        v.push_back({row,column,root->val});
        helper(root->left,v,row+1,column-1);
        helper(root->right,v,row+1,column+1);
    }
};