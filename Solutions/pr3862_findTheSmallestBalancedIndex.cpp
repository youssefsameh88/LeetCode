#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int smallestBalancedIndex(vector<int>& nums) {
        int n = nums.size();
        unsigned long long ps = 0, sm = 1;
        for(int i = 0; i < n; i++) ps += nums[i];

        for(int i = n-1; i >= 0; i--){
            ps -= nums[i];
            if(ps == sm) return i;
            if(sm > ps/nums[i]) break;
            sm *= nums[i];
        }
        return -1;
    }
};