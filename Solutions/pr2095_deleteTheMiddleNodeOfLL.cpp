
 //Definition for singly-linked list.
 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if(!head || !head->next) return nullptr;

        ListNode * curr = head;
        int size = 0;

        while(curr){
            size++;
            curr = curr->next;
        }
        if(size == 2){
            head->next = nullptr;
            return head;
        }

        int mid = size/2;

        curr = head;
        ListNode * prev = nullptr;
        ListNode * next = head->next;

        while(mid > 0){
            prev = curr;
            curr = curr->next;
            next = next->next;
            mid--;
        }
        prev->next = next;
        return head;
    }
};