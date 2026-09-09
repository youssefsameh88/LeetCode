#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int l = 1, r = *max_element(nums.begin(), nums.end());
        long ans = 0;
        while(l <= r){
            int mid = l + (r-l)/2;
            int m = helper(nums, mid);
            if(m > threshold){
                l = mid + 1;
            }
            else {
                ans = mid;
                r = mid - 1;
            }
        }
            return ans;
        
    }
    long helper(vector<int>& v, int div){
        long sum = 0;
        for(double num : v) sum += ceil(num/div);
        return sum;
    }
};