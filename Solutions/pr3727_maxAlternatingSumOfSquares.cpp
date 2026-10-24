#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        for(int& n : nums) n = n*n;
        nth_element(nums.begin(), nums.begin()+nums.size()/2 ,nums.end());
        int l = 0, r = nums.size()-1;
        long long ans = 0;
        while(l < r) ans += nums[r--] - nums[l++];
        if(l == r) ans += nums[l];
        return ans;
    }
};
