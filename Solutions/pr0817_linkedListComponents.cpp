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
    int numComponents(ListNode* head, vector<int>& nums) {
        int total = 0;
        bool connected = false;
        ListNode* curr = head;
        ListNode* last = nullptr;
        unordered_set <int> set;
        for(int n : nums)
            set.insert(n);

        while(curr){
            if(set.find(curr->val) == set.end()){
                if(connected)
                    total++;
                    connected = false;
            }
            else connected = true;
            if(!curr->next) last = curr;
            curr = curr->next;
        }
        if(set.find(last->val) != set.end()) total++;
        return total;
    }
};