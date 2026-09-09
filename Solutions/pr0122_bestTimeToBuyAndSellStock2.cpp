#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mn = INT_MAX, profit = 0;
        for(int i = 0; i < prices.size(); i++){
            if(prices[i] <= mn) mn = prices[i];
            else{
                if(i+1 == prices.size() || prices[i+1] < prices[i] ){
                    profit += prices[i] - mn;
                    mn = INT_MAX;
                } 
            }
        }
        return profit;
    }
};
