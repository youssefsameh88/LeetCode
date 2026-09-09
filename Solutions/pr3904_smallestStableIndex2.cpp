#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int l = 0, r = nums.size() - 1;
        int mn = INT_MAX, mx = INT_MIN;
        vector<pair<int,int>> v(nums.size());
        while (l < nums.size()){
            if(nums[l] > mx) mx = nums[l];
            if(nums[r] < mn) mn = nums[r];
            v[l].first = mx;
            v[r].second = mn;
            l++, r--;
        }
        int score = INT_MAX;
        for(int i = 0; i < nums.size(); i++){
            if(v[i].first - v[i].second <= k) return i;
        }
        return -1;
    }
};
