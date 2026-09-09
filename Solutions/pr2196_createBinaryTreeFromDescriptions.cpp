#include <unordered_map>
#include <unordered_set>
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
    TreeNode* createBinaryTree(vector<vector<int>>& d) {
        unordered_map<int, TreeNode*> map;
        for(int i = 0; i < d.size(); i++){
            map[d[i][1]] = new TreeNode(d[i][1]);
        }
        TreeNode* root = nullptr;

        for(int i = 0; i < d.size(); i++){
            if(!map.count(d[i][0])){
                root = map[d[i][0]] = new TreeNode(d[i][0]); 
            }
                if(d[i][2]) map[d[i][0]]->left = map[d[i][1]];
                else map[d[i][0]]->right = map[d[i][1]];
        }
        return root;
    }
};
