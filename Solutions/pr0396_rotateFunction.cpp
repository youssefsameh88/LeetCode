#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int sum = 0, ans = INT_MIN, fn = 0;
        for(int i = 0; i < nums.size() ; i++){
            fn += i*nums[i];
            sum += nums[i];
        }
        int m = nums.size() - 1;
        for(int i = nums.size() - 1; i >= 0 ; i--){
            fn = fn - m * nums[i] + sum - nums[i];
            ans = max(ans,fn);
        }
        return ans;
    }
};
