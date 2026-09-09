#include <vector>
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
    TreeNode* recoverFromPreorder(string traversal) {
        int s  = traversal.size();
        vector<int> levels;
        vector<int> roots;
        levels.push_back(0);
        int i = 0;
        while(i < s){

            string str = "";
            while(i < s && traversal[i] != '-')
                str += traversal[i++];

            int count = 0;
            while(i < s && traversal[i] == '-' ){
                count++, i++;
            }
           if(str != "") roots.push_back(stoi(str));
            levels.push_back(count);
        }
        levels.pop_back();
         i = 0;
       return helper(levels,roots,i, 0);
    }
    TreeNode* helper(vector<int>& levels, vector<int>& roots, int& i, int depth){
        if(i >= roots.size() || depth != levels[i]) return nullptr;
        TreeNode* node = new TreeNode(roots[i]);
        i++;
        node->left = helper(levels,roots,i,depth+1);
        node->right = helper(levels,roots,i,depth+1);
        return node;
    }
};
