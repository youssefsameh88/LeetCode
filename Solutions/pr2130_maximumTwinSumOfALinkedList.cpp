#include<iostream>
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
    int pairSum(ListNode* head) {
        if(!head->next->next) return head->val + head->next->val;
        ListNode* fast = head->next;  
        ListNode* slow = head;
        while(fast->next){
            slow = slow->next;
            fast = fast->next;
            fast = fast->next;
        } 
        ListNode* temp = slow->next;
        slow->next = nullptr; 
        temp = reverse(temp);
        ListNode* curr = head;
        int maxSum = 0;
        while(curr){
            maxSum = max(maxSum, curr->val + temp->val);
            curr = curr->next;
            temp = temp->next;
        }
        return maxSum;
    }

    ListNode* reverse(ListNode* head){
        if(!head || !head->next) return head;
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while(curr){
            ListNode* next = curr->next;
            curr->next = prev; 
            prev = curr;
            curr = next;
        }
        return prev;
    }
};