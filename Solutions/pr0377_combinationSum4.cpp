#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<unsigned long long> dp(target + 1);
        dp[0] = 1;

        for (int i = 1; i <= target; i++) {
            for (int c : nums) {
                if (i >= c)
                    dp[i] += dp[i - c];
            }
        }

        return (int)dp[target];
    }
};