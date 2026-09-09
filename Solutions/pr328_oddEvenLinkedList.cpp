
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
        //1-indexed
    ListNode* oddEvenList(ListNode* head) {

        if(head == nullptr || head->next == nullptr || head->next->next == nullptr) return head;
        bool isOdd = true;

        ListNode * curr = head->next->next;
        ListNode * oddLast = head;
        ListNode * evenFirst= head->next;
        ListNode * evenLast = head->next;

        oddLast->next = nullptr;
        evenLast->next = nullptr;
        while(curr != nullptr){
            if(isOdd){
                oddLast->next = curr;
                oddLast = oddLast->next;
                curr = curr->next;
                oddLast->next = nullptr;
                isOdd = !isOdd;
            }
            else{
                evenLast->next = curr;
                evenLast = evenLast->next;
                curr = curr->next;
                evenLast->next = nullptr;
                isOdd = !isOdd;
            }
        }
        oddLast->next = evenFirst;
        return head;
        
    }
};