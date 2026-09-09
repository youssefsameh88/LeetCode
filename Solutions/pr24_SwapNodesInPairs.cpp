#include <queue>
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
    ListNode* swapPairs(ListNode* head) {
        if(!head || !head->next) return head;
        queue<ListNode*> q1;
        queue<ListNode*> q2;
        ListNode* curr = head;
        int i = 0;
        while(curr){
            if(i%2 == 0)  q1.push(curr); 
            else q2.push(curr); 
            curr = curr->next;
            i++;
        }
        ListNode* dummy = new ListNode(1);
        ListNode* dumdum = dummy;
        while(!q2.empty()){
            dumdum->next = q2.front();
            q2.pop();
            dumdum = dumdum->next;
            dumdum->next = q1.front();
            q1.pop();
            dumdum = dumdum->next; 
        }
        if(!q1.empty()) {
        dumdum->next = q1.front();
         dumdum->next->next = nullptr;
        }
        else dumdum->next = nullptr;
        return dummy->next;
    }
};