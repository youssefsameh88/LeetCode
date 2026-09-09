#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumCandies(vector<int>& candies, long long k) {
        long long sum = accumulate(candies.begin(), candies.end(),0LL);
        if(sum < k) return 0;
        sort(candies.begin(), candies.end());
        int l = 1, r = candies.back(), ans = 0;
        while(l <= r){
            int mid = (l+r)/2;
            if(ok(mid,k,candies)){
                ans = mid;
                l = mid + 1;
            }
            else {
                r = mid - 1;
            }
        } 
        return ans;   
    }
       bool ok(int mid, int k, vector<int>& v){
            long long x = 0;
            for(int num : v) x += num / mid;
            return x >= k; 
        }   

};
