#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int missingInteger(vector<int>& nums) {
        set<int> s(nums.begin(),nums.end());
        int i = 0, sum = 0;
        while(i < nums.size()-1 && nums[i] == nums[i+1]-1) sum+=nums[i], i++;
        if(!i){
            sum = nums[0];
            goto ps;
        }
        if(nums[i] - nums[i-1] == 1) sum += nums[i];
        ps : while(true){
            if(!s.count(sum)) return sum;
            sum++;
        }
    }
};