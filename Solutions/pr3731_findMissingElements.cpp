#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        unordered_set<int> set(nums.begin(), nums.end());
        int mn = INT_MAX, mx = INT_MIN;
        for(int num : nums){
            mn = min(mn,num);
            mx = max(mx,num);
        }
        vector<int> ans;
        for(int i = mn+1; i < mx; i++) if(!set.count(i)) ans.push_back(i);
        return ans;
    }
};