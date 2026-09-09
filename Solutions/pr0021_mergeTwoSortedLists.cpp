struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(!list1) return list2; 
        if(!list2) return list1;
        ListNode *dummy = new ListNode(0);
        ListNode * curr1 = list1->val >= list2->val ? list2 : list1;
        dummy->next = curr1; 

        ListNode * curr2 = curr1 == list1 ? list2 : list1;
        ListNode * saver2 = curr2->next;
        ListNode * prev1 = nullptr;
        while(curr2){
            if(curr1->next && curr2->val <= curr1->next->val){
                curr2->next = curr1->next;
                curr1->next = curr2;
                curr1 = curr1->next;
                curr2 = saver2;
                if(saver2) saver2 = saver2->next;
            }
            else if(!curr1->next){
                curr1->next = curr2;
                return dummy->next;
            }
            else{
                curr1 = curr1->next;
            }
        }
        return dummy->next;
    }
};