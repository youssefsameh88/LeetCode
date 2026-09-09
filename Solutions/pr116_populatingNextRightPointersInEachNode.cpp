#include <vector>
using namespace std;
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(nullptr), right(nullptr), next(nullptr) {}

    Node(int _val) : val(_val), left(nullptr), right(nullptr), next(nullptr) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
public:
    Node* connect(Node* root) {
        int maximumDepth = maxDepth(root);
        vector<vector<Node*>> l(maximumDepth,vector<Node*>(0));
        int n = 0, level = 0;
        collect(root,level,l);
        if(l.empty()) return nullptr;

        for(int i = 0 ; i < l.size() ; i ++){
            for(int j = 0 ; j < l[i].size() ; j++){
                if(j < l[i].size()-1) l[i][j]->next = l[i][j+1];
                else l[i][j]->next = nullptr;
            }
        }
        return l[0][0]; 
    }
   void collect(Node* root, int level, vector<vector<Node*>>& l){
        if(!root) return;
        l[level].push_back(root);
        collect(root->left,level+1,l);
        collect(root->right,level+1,l);
    }
    int maxDepth(Node* root) {
       if(!root) return 0;
       int left = 1 + maxDepth(root->left);
       int right = 1 + maxDepth(root->right);
       return max(left, right);
    }
};