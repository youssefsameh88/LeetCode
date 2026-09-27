#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minDays(int n) {
        vector<int> dp(n+1), v;
        for(int i = 0; i < 448; i++) v.push_back(i*(i+1)/2);
        for(int i = 0; i < v.size(); i++){
            if(v[i] < dp.size()) dp[v[i]] = i;
        }
        return helper(n, dp,v);
    }
    int helper(int n,vector<int>& dp, vector<int>& v){
        if(dp[n]) return dp[n];
        int mn = INT_MAX;
        
        for(int i = 1; i < v.size(); i++){
            if(v[i] >= n) break;
            mn = min(mn, helper(n-v[i],dp,v)+ i+1);
        }
        return dp[n] = mn;
    }
};
