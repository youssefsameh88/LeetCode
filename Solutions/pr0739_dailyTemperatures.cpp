#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& t) {
        vector<int> ans(t.size());
        stack<int> st;
        for(int i = t.size()-1; i >= 0; i--){
            while(!st.empty() && t[st.top()] <= t[i]) st.pop();
            ans[i] = st.empty() ? 0 : st.top()-i;
            st.push(i);
        }
        return ans;
    }
};