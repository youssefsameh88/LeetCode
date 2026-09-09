struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution { // WITH THE HELP OF THE SOLUTION
public:
    bool isSubPath(ListNode* head, TreeNode* root) {
        if(!root) return false;
        if(path(head, root)) return true;
        return isSubPath(head,root->left) || isSubPath(head,root->right);
}  
bool path(ListNode*head, TreeNode* root){
        if(!head) return true;
        if(!root || root->val != head->val ) return false;
        return path(head->next, root->left) || path(head->next, root->right);
    }
    
};