#include <cmath>
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        int size = 0, kRev = 0;
        ListNode* curr = head;
        ListNode* temp1 = nullptr;
        ListNode* temp2 = nullptr;
        while(curr) {
            size++;
            curr = curr->next;
        }
        kRev = size - k + 1 ;
        curr = head;
        int a = std::max(k,kRev);
        for(int i = 1 ; i <= a ; i++){
            if(i == k) temp1 = curr;
            if(i == kRev) temp2 = curr;
            curr = curr->next;
        }
        int t = temp2->val;
        temp2->val = temp1->val;
        temp1->val = t;
        return head;
    }
};