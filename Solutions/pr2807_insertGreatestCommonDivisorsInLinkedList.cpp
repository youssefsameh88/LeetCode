#include <numeric>
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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* curr = head;
        ListNode* next = head->next;
        while(next){
            curr->next = new ListNode(gcd(curr->val, next->val),next);
            curr = next;
            next = next->next;
        }
        return head;
    }
};
