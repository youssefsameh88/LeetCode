#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxScore(vector<int>& nums, int k) {
        if(k == 1) return max(nums[0], nums.back());
        int ps = 0;
        for(int i = 0; i < k; i++){
            ps += nums[i];
        }
        int mx = ps, j = 0;
        for(int i = k-1; i >=0; i--){
            ps += nums[nums.size()+i-k] - nums[i];
            mx = max(mx,ps);
        }
        return mx;
    }
};