
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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == nullptr) return nullptr;
        if(head->next == nullptr || k == 0) return head;

        ListNode *dummy = new ListNode(2);
       dummy->next = head;

        ListNode *last = head;
        int length = 1;
        while(last->next != nullptr){
            last = last->next;
            length++;
        }
        last->next = head;
        k = k % length;
        int steps = length - k - 1;
        ListNode *curr = head;
        for(int i = 0 ; i < steps ; i++)
            curr = curr->next;

            dummy->next = curr->next;
            curr->next = nullptr;
            return dummy->next;
    }
};