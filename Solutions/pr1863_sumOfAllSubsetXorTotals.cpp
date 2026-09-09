#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int ans = 0;
    int subsetXORSum(vector<int>& nums) {
        helper(0,0,nums);
        return ans;
    }   
    void helper(int i, int currXOR,vector<int>& nums){
        if(i == nums.size()){
            ans += currXOR;
            return;
        }
        helper(i+1, currXOR ^ nums[i], nums);
        helper(i+1, currXOR,nums);
    }
};
