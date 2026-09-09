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
    vector<int> inorderTraversal(TreeNode* root) {
        vector <int> v;
        if(root)addNums(root,v);
        return v;
    }
    void addNums(TreeNode* root , vector<int> &v){
        
        if(root->left) addNums(root->left , v);
        v.push_back(root->val);
        if(root->right)addNums(root->right,v);
    }
};