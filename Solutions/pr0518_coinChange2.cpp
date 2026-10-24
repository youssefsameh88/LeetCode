#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<unsigned long long> dp(amount+1);
        dp[0] = 1;
        for(int c : coins){
            for(int i = c; i < dp.size(); i++)
                dp[i] += dp[i-c];
        }
        return dp[amount];
    }
};
