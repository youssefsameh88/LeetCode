#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int idx = max_element(nums.begin(), nums.end()) - nums.begin();
        sort(nums.begin(),nums.end());
        return nums.back()>= 2*nums[nums.size()-2] ? idx : -1;
    }
};