#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maximumScore(vector<int>& nums) {
        long long ps = 0, ans = LONG_MIN;
        for(int num : nums) ps += num;
        int sm = INT_MAX;
        for(int r = nums.size()-1; r > 0; r--){
            ps -= nums[r];
            sm = min(sm, nums[r]);
            ans = max(ps-sm, ans);
        }
        return ans;
    }
};
