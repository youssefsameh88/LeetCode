#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maxStrength(vector<int>& nums) {
        if(nums.size() == 1) return nums[0]; 
        sort(nums.begin(), nums.end());
        int n = nums.size(), nc = 0, i = n - 1;
        long long ans = 1;
        bool flag = false;
        for(int j = 0; j < n && nums[j] < 0; j++) nc++;
        while(i >= 0 && nums[i] > 0) {
            ans *= nums[i--];
            flag = true;
        }
        i = 0;
        while(i < nc - nc%2){ 
            ans *= nums[i++];
            flag = true;
        }
        return flag ? ans : 0;
    }
};
