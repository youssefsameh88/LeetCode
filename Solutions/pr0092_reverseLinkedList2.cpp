#include <iostream>
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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(!head || !head->next || left == right) return head;
        ListNode* temp1 = nullptr;
        ListNode* temp = nullptr;
        ListNode* temp2 = nullptr;
        ListNode* curr = head;
        int i = 1;
        left--;
        while(i <= right){
            if(i == left){
                temp1 = curr;
                temp = curr->next;
                curr = temp;
                i++;
                temp1->next = nullptr;
                continue;
            }  
            else if(i == right){
                temp2 = curr->next;
                curr->next = nullptr;
            }
            curr = curr->next;
            i++;
        }
            if(left > 0){
                temp1->next = reverse(temp);
        curr = temp;
        while(curr->next) curr = curr->next;
        curr->next = temp2;
        return head;
            }
            head = reverse(head);
            curr = head;
            while(curr->next) curr = curr->next;
            curr->next = temp2;
        return head;
    }

    ListNode* reverse(ListNode* head){
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while(curr){
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
        
        for(ListNode* curr = head ; curr ; curr = curr->next){

        }
    }

};