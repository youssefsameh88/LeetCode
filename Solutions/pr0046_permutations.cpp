#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> permute(vector<int>& nums) {
        vector<bool> used(nums.size());
        vector<int> v;
        helper(nums, v, used);
        return ans;
    }
    void helper(vector<int>& nums, vector<int>& v, vector<bool>& used) {
        if(v.size() == nums.size()){
            ans.push_back(v);
            return;
        }
        for(int i = 0; i < nums.size(); i++){
            if(!used[i]){
                used[i] = true;
                v.push_back(nums[i]);
                helper(nums,v,used);
                used[i] = false;
                v.pop_back();
            }
        }
    }
};
