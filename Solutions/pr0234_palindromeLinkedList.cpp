struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if(!head->next) return true;
        ListNode* dummy = new ListNode(0,head);
        ListNode* fast = dummy;
        ListNode* slow = dummy;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* c1 = reverse(slow->next);
        ListNode* c2 = head;
        while(c1 && c2){
            if(c1->val != c2->val) return false;
            c1 = c1->next;
            c2 = c2->next;
        }
        return true;
    }
    ListNode* reverse(ListNode* node){
        if(!node) return nullptr;
        ListNode* prev = nullptr;
        ListNode* curr = node;
        while(curr){
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
};
