#include <vector>
#include <unordered_set>
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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set <int> s(nums.begin(),nums.end());
        
        while(head && s.find(head->val) != s.end()) head = head->next;
        ListNode* curr = head;
        while(curr){
            if(curr->next && s.find(curr->next->val) != s.end())
                curr->next = curr->next->next;

            curr = curr->next;
    }
    return head;
}
};