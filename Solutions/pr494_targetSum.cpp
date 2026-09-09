#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int ans = 0;
    int findTargetSumWays(vector<int>& nums, int target) {
        helper(nums,target,0,0);
        return ans;
    }
    void helper(vector<int>& nums, int target, int sum, int i){
        if(i == nums.size()){
            if(sum == target) ans++;
            return;
        }
        helper(nums, target, sum + nums[i], i+1);
        helper(nums, target, sum - nums[i], i+1);
    }
};