#include <bits/stdc++.h>
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
    vector<int> nextLargerNodes(ListNode* head) {
        vector<ListNode*> v = reverse(head);
        ListNode *curr = v[0];
        stack<int> st;
        vector<int> ans(v[1]->val);
        for(int i = ans.size()-1; i >= 0; i--){
            while(!st.empty() && st.top() <= curr->val) st.pop();
            ans[i] = st.empty() ? 0 : st.top();
            st.push(curr->val);
            if(curr->next)curr = curr->next;
        }
        return ans;
    }
    vector<ListNode*> reverse(ListNode* head){
        if(!head) return {nullptr,nullptr};
        ListNode *prev = nullptr;
        ListNode *curr = head;
        int size = 0;
        while(curr){
            ListNode *next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            size++;
        }
        return {prev,new ListNode(size)};
    } 
};
