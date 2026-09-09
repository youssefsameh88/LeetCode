#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        nums[1] = max(nums[0],nums[1]);
        int mx = nums[0];
        for(int i = 2; i < nums.size(); i++){
            mx = max(mx,nums[i-2]);
            nums[i] = max(nums[i-1], mx + nums[i]);
        }
        return nums.back();
    }
};