#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numSquares(int n) {
        vector<int> perf;
        for(int i = 1; i*i <= n; i++){
            perf.push_back(i*i);
        }
        vector<int> dp(n+1,INT_MAX-1);
        dp[0] = 0;
        for(int i = 1; i <= n; i++){
            for(int pf : perf){
                if(i - pf >= 0)
                    dp[i] = min(dp[i],1+ dp[i-pf]);
            }
        }
        return dp[n] == INT_MAX-1 ? -1 : dp[n];
        
    }
};
