#include <vector>
class Solution {
public:
    double findMaxAverage(std::vector<int>& nums, int k) {
        if(k == 1){
           int Max = nums[0];
           for(int num : nums)
              if(num > Max) Max = num;
           return Max;
        }
        int ans = 0, sum = 0;
        for(int i = 0 ; i < k ; i++)
            sum += nums[i];
        ans = sum;
        for(int i = k; i < nums.size() ; i++){
            sum = sum - nums[i-k] + nums[i];
            if(sum > ans) ans = sum;
        }
        return (double)ans/k;
    }
};