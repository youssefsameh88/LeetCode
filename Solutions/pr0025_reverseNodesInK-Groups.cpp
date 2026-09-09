#include <vector>
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(k == 1 || !head || !head->next) return head;

        std::vector<ListNode*> lists;
        ListNode * first = head;
        ListNode * curr = head;
        ListNode * next = head->next;

        int n = 1;
        while(curr){
            while((n % k) && next){
                curr = curr->next;
                next = next->next;
                n++;
            }
            curr->next = nullptr;
            if(!next) break;
            n = 1;
            lists.push_back(reverseList(first));
            curr = next;
            first = next;
            next = next->next;
        }
        curr = first;
        int size = 0;
        while(curr){
            size++;
            curr = curr->next;
        }
        if(size%k == 0)
        lists.push_back(reverseList(first));
        else
        lists.push_back(first);

        ListNode * ptr = lists[0];
        for (int i = 0; i < lists.size() - 1; i++){
            while(ptr->next) ptr = ptr->next;
            ptr->next = lists[i + 1];
        }

        return lists[0];
    }

    ListNode* reverseList(ListNode* head) {
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