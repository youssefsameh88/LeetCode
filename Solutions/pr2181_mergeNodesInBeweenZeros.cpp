#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeNodes(ListNode* head) {
        ListNode* dummy = new ListNode(0);
        ListNode* dumdum = dummy;
        ListNode* curr = head->next;
        int sum = 0;
        while(curr){
            if(!curr->val){
                dumdum->next = new ListNode(sum);
                dumdum = dumdum->next;
                sum = 0;
            }
            sum += curr->val;
            curr = curr->next;
        }
        return dummy->next;
    }
};