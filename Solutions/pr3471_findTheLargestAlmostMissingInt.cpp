#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int> freq;
        for(int num : nums) freq[num]++;
        if(k == n) return *max_element(nums.begin(),nums.end());
        if(k == 1){
            int mx = -1;
            for(auto [a,b] : freq) if(b == 1) mx = max(mx,a);
            return mx;
        }
        if(freq[nums[0]] == 1 && freq[nums[n-1]] == 1) return max(nums[0],nums[n-1]);
        else if(freq[nums[0]] == 1) return nums[0];
        else if(freq[nums[n-1]] == 1) return nums[n-1];
        return -1;
    }
};