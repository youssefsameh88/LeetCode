#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> ans;
    int t;
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        t = target;
        vector<int> v;
        helper(candidates, v, 0, 0);
        return ans;
    }
    void helper(vector<int>& nums, vector<int>& v, int start, int sum){
        if(sum == t){
            ans.push_back(v);
            return;
        }
        if(sum > t) return;
        for(int i = start; i < nums.size(); i++){
            v.push_back(nums[i]);
            helper(nums,v,i,sum + nums[i]);
            v.pop_back();
        }
    }
};
