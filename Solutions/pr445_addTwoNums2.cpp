
 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        l1 = reverseList(l1);
        l2 = reverseList(l2);

         ListNode *dummy = new ListNode(0);
        ListNode *ans = dummy;
            int carry = 0;

        while (l1|| l2){
            int n1 = l1 != nullptr ? l1->val : 0;
            int n2 = l2 != nullptr ? l2->val : 0;


            ans->next = new ListNode((n1 + n2 + carry) % 10);
                carry = (n1 + n2 + carry) / 10 ;
              
            if (l1 != nullptr) l1 = l1->next;
            if (l2 != nullptr) l2 = l2->next;
            ans = ans->next; 
            
        }
        if(carry){
            ans->next = new ListNode(1);
        }
        return reverseList(dummy->next) ;
      
    }

    ListNode* reverseList(ListNode* list) {
        if(list == nullptr || list->next == nullptr) return list;
        ListNode * ptr1  = nullptr;
        ListNode * curr = list;
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