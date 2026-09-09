#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1, r = 1e9;
        long ans = 0;
        while(l <= r){
            int mid = l + (r-l)/2;
            long m = bites(piles,mid);
            if(m > h){
                l = mid + 1 ;
            }
            else{
                ans = mid;
                r = mid-1;
            }
        }
        return ans;
    }
    long bites(vector<int>& v, int k){
        long  sum = 0;
        for(double num : v){
            sum += ceil(num/k);
        }
        return sum;
    }
};