#include <string>
#include <vector>
#include <unordered_map>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
 unordered_map <TreeNode*, string> map;
  string s;
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        map[root] = "";
        helper(root->left,true);
        helper(root->right,false);
        int d1 = map[target].size();
        vector<int> trees;
        for(auto &[node,path] : map){
            int i = 0, total = d1 + path.size();
            while(i < path.size() && i < d1 && path[i] == map[target][i]) total-=2,i++;
            if(total == k) trees.push_back(node->val);
        }
        return trees;
    }
    void helper(TreeNode* root, bool isLeft){
        if(!root) return;
        if(isLeft) s.push_back('L');
        else s.push_back('R');
        map[root] = s;
        helper(root->left,true);
        helper(root->right,false);
        s.pop_back();
    }
};
