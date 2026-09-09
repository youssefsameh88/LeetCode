#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        int Min = INT_MAX;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] != target) continue;
            Min = min(Min,abs(i-start));
        }
        return Min;
    }
};
