#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int> ps(nums.size()+1);
        for(int i = 0; i < queries.size(); i++){
            ps[queries[i][0]] -= 1;
            ps[queries[i][1]+1] += 1;
        }
        int count = 0;
        for(int i = 0; i < nums.size(); i++){
            count += ps[i];
            nums[i] += count;
            if(nums[i] > 0) return false;
        }
        return true;
    }
};
