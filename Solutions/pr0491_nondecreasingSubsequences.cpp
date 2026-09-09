#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<int> path;
        helper(nums,path,0);
        sort(ans.begin(),ans.end());
        ans.erase(unique(ans.begin(),ans.end()),ans.end());
        return ans;
    }
    void helper(vector<int>& nums,vector<int>& path, int i){
        if(i == nums.size()){
            if(path.size() > 1) 
                ans.push_back(path);
            return;
        }
        if(path.empty() || (!path.empty() && nums[i] >= path.back())){
            path.push_back(nums[i]);
            helper(nums,path, i+1);
            path.pop_back();
        }
            helper(nums,path,i+1);
            
    }
};
