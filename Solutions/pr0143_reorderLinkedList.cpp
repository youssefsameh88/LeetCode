#include <vector>
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
    void reorderList(ListNode* head) {
        vector <ListNode*> v;
        ListNode* curr = head;
        while(curr){
            v.push_back(curr);
            curr = curr->next;
        }
        int i = 1, j = v.size() -1 ;
        curr = head;
        while(i <= j){
            curr->next = v[j--];
            curr = curr->next;
            curr->next = v[i++];
            curr = curr->next;
        }
        curr->next = nullptr;
    }
};