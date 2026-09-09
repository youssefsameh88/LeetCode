#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<vector<int>>> dp{11,vector<vector<int>>(2,vector<int>(9,-1))};
    int solve(string &s, int idx, bool tight, int cnt){
        if(idx == s.size()) return cnt;
        if(dp[idx][tight][cnt] != -1) return dp[idx][tight][cnt];
        int lb = 0;
        int ub = tight ? s[idx] - '0' : 9;

        int ans = 0;
        for(int dig = lb; dig <= ub; dig++){
            ans += solve(s,idx+1,tight && (dig == ub), cnt + (dig == 1));
        }
        return dp[idx][tight][cnt] = ans;
    }
    int countDigitOne(int n) {
        string s = to_string(n);
        return solve(s,0,1,0);
    }
};
