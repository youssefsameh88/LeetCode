#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int currSum = nums[0], mx = nums[0];
        for(int i = 1; i < nums.size(); i++){
            currSum = max(nums[i],currSum + nums[i]);
            mx = max(mx,currSum);
        }
        return mx;
    }
};