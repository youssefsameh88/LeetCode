#include <bits/stdc++.h>
using namespace std;

#define pii pair<int,int>
#define f first
#define s second
class Solution {
public:
    vector<pii> merged;
    int longestValidParentheses(string str) {
        if(str.empty()) return 0;  
        stack<int> st;
        vector<pii> intervals;
        for(int i = 0; i < str.size(); i++){
            if(str[i] == '(') st.push(i);
            else if(!st.empty()){
                intervals.push_back({st.top(), i});
                st.pop();
            }
        }
        if(intervals.empty()) return 0;
        if(intervals.size() > 1){
            merge(intervals);
            int ans = 0;
            for(pii& p : merged) ans = max(ans, p.s-p.f + 1);
            return ans;
        }
        return intervals[0].s - intervals[0].f + 1;

    }
    void merge(vector<pii>& v){
        sort(v.begin(), v.end());
        pii p = v[0];
        for(int i = 1; i < v.size(); i++){
            if(v[i].f == p.s+1 || (v[i].f > p.f && v[i].f < p.s)) {
                p.s = max(v[i].s, p.s);
            }
            else{
                merged.push_back(p);
                p = v[i];
            }
                if(i == v.size()-1) merged.push_back(p);
        }
    }
};
