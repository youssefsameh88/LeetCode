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
    ListNode* partition(ListNode* head, int x) {
        if(!head || !head->next) return head;
        queue<ListNode*> q1;
        queue<ListNode*> q2;
        ListNode* dummy = new ListNode(0);
        ListNode* dumdum = dummy;
        for(ListNode* curr = head ; curr ; curr = curr->next){
            if(curr->val < x) q1.push(curr);
            else q2.push(curr);
        }
        while(!q1.empty()){
            dumdum->next = q1.front();
            dumdum = dumdum->next;
            q1.pop();
        }
        while(!q2.empty()){
            dumdum->next = q2.front();
            dumdum = dumdum->next;
            q2.pop();
        }
        dumdum->next = nullptr;
        return dummy->next;
    }
};