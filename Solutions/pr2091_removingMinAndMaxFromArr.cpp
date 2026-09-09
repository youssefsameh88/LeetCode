#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        if(nums.size() < 3) return nums.size();
        int maxIdx = 0,minIdx = 0;
        int maxNum = INT_MIN,minNum = INT_MAX;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] > maxNum){
                maxIdx = i;
                maxNum = nums[i];
            }
             if(nums[i] < minNum){
                minIdx = i;
                minNum = nums[i];
            }
        }
        int ans1 = max(minIdx,maxIdx) + 1;
        int ans2 = nums.size() - min(minIdx,maxIdx);
        int ans3 = nums.size() - max(minIdx,maxIdx) + min(minIdx,maxIdx) + 1;

        return min(min(ans1,ans2),ans3);  
    }
};
