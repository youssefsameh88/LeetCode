#include <vector>
#include <iostream>
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
int size ;
std::vector <int> values;

    Solution(ListNode* head) {
        srand(time(0));
        ListNode * curr = head;
        while(curr !=nullptr){
            values.push_back(curr->val);
            curr = curr->next;
        }
        size = values.size();
    }
    
    int getRandom() {
        int rnum = rand() % size;

        return values[rnum];
        
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */