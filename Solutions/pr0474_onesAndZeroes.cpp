#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int sz = strs.size();
        vector<int> z(sz);
        for(int i = 0; i < sz; i++){
             for(char& c : strs[i]) z[i] += c == '0';
        }
        vector<vector<vector<int>>> dp(sz, vector<vector<int>>(m+1, vector<int>(n+1)));
        int ones = strs[0].size() - z[0];
        for (int j = z[0]; j <= m; j++) {
            for (int k = ones; k <= n; k++) 
                dp[0][j][k] = 1;
        }
        for(int i = 1; i < sz; i++){
            int size = strs[i].size();
            for(int j = 0; j <= m; j++){
                for(int k = 0; k <= n; k++){
                    dp[i][j][k] = dp[i-1][j][k];
                    if(j >= z[i] && k >= size-z[i])
                        dp[i][j][k] = max(dp[i][j][k], 1+dp[i-1][j-z[i]][k-(size-z[i])]);
                }
            }
        }
        return dp.back().back().back();
    }
};
