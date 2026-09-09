#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        unordered_map<int, vector<int>> map;
        vector<int> ans;
        for(int i = 0; i < nums.size(); i++){
            map[nums[i]].push_back(i);
        }
        for(int i = 0; i < queries.size(); i++){
            int x = nums[queries[i]];
            int sz = map[x].size();
            if(sz == 1){
                ans.push_back(-1);
                continue;
            }
            int j = lower_bound(map[x].begin(), map[x].end(), queries[i]) - map[x].begin();
            int a = map[x][(j+1)%sz], b = queries[i], c = map[x][(j-1+sz)%sz];
            int mn1 = min(abs(a-b), abs(c-b));
            int mn2 = min(nums.size() - abs(a-b), nums.size() - abs(c-b));
            ans.push_back(min(mn1,mn2));
        }
        return ans;
    }
};
