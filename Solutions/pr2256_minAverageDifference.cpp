#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        vector<long long> ps(nums.size());
        ps[0] = nums[0];
        for(int i = 1; i < nums.size(); i++){
            ps[i] += nums[i] + ps[i-1];
        }
        int avg = INT_MAX, idx = 0;
        for(int i = 0; i < nums.size(); i++){
            int x = i == nums.size() - 1 ? ps[i]/(i+1) :
            abs(ps[i]/(i+1) - (ps.back()-ps[i])/((int)nums.size()-i-1));
            if(x < avg){
                avg = x;
                idx = i;
            }
        }
        return idx;
    }
};