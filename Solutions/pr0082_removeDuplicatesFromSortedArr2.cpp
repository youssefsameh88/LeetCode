struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode * dummy = new ListNode(1000);
        ListNode * curr1 = dummy; 
        ListNode * curr2 = head; 

        while(curr2){
            if(curr2->val == curr2->next->val){
                while(curr2 && curr2->val == curr2->next->val)
                    curr2 = curr2->next;

                if(!curr2) break;
                curr2 = curr2->next;
                continue;
            }
            curr1->next = curr2;
            curr2 = curr2->next;
            curr1 = curr1->next;
            curr1->next = nullptr;   
        }
        return dummy->next;
    }
};