#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mn = INT_MAX, mx = 0;
        for(int price : prices){
            mn = min(mn, price);
            mx = max(mx,price - mn);
        }
        return mx;
    }
};