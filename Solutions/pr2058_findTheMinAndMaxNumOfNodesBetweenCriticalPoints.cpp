#include <vector>
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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> cp;
        ListNode* prev = head;
        ListNode* curr = head->next;

        int i = 1;
        while(curr->next){
             int p = prev->val, c = curr->val, n = curr->next->val;
            if((c > p && c > n) || (c < p && c < n)) cp.push_back(i);
            i++;
            prev = curr;    
            curr = curr->next;
        }
        if(cp.size() <= 1) return {-1,-1};
        int maxDist = cp.back() - cp.front();
        int minDist = i;

        for(int i = 0; i < cp.size() - 1; i++) minDist = min(minDist, cp[i+1] - cp[i]);

        return {minDist,maxDist};
    }
};
