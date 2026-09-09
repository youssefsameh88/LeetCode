struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* doubleIt(ListNode* head) {
        head = reverse(head);
        ListNode* curr = head;
        int carry = 0;
        while(curr){
            curr->val = 2*curr->val + carry; 
            if(curr->val > 9){
                carry = 1;
                curr->val -= 10; 
            }
            else carry = 0;
            if(!curr->next && carry){
                curr->next = new ListNode(1);
                break;
            }
            curr = curr->next;
        }
        return reverse(head);
    }
    ListNode* reverse(ListNode* node){
        if(!node || !node->next) return node; 
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