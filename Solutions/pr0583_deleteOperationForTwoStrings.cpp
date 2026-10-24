#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minDistance(string s, string t) {
        vector<vector<int>> dp(s.size()+1, vector<int>(t.size()+1));

        for (int i = 1; i < dp.size(); i++) {
            for (int j = 1; j < dp[0].size(); j++) {
                if (s[i-1] == t[j-1]) dp[i][j] = dp[i-1][j-1] + 1;
                else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
        return s.size() + t.size() - 2*dp.back().back();
    }
};