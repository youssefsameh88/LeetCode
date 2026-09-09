struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if(!head) return nullptr;
        ListNode* dummy = new ListNode(0,head);
        ListNode* curr = dummy;
        while(curr){
            if(curr->next && curr->next->val == val){
                curr->next = curr->next->next;
                continue;
            } 
            curr = curr->next;
        }
        return dummy->next;
    }
};
