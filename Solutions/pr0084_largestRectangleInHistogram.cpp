#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& h) {
        vector<pair<int,int>> v(h.size());
        stack<int> st;
        for(int i = 0; i < h.size(); i++){
            while(!st.empty() && h[st.top()] >= h[i]) st.pop();
            v[i].first = st.empty()? -1: st.top();
            st.push(i);
        }
        st = stack<int>();
        for(int i = h.size()-1; i >= 0; i--){
            while(!st.empty() && h[st.top()] >= h[i]) st.pop();
            v[i].second = st.empty()? h.size(): st.top();
            st.push(i);
        }
        int ans = 0;
        for(int i = 0; i < h.size(); i++){
            ans = max(ans, h[i]*(v[i].second-v[i].first-1));
        }
        return ans;
    }
};
