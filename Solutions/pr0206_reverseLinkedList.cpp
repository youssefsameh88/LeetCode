#include <stack>
struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };



  
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head == nullptr || head->next == nullptr) return head;
        ListNode * ptr1  = nullptr;
        ListNode * curr = head;
        ListNode * ptr2 = curr->next;



        while(curr != nullptr){
            ptr2 = curr->next;
            curr->next = ptr1;
            ptr1 = curr;
            curr = ptr2;
        }
        return ptr1;
        
    }
};