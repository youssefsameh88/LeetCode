#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int findLHS(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int l = 0, r = 0;
        int Max = 0;
        while(r < nums.size()){
            if(nums[r] - nums[l] <=1) {
                if(nums[r] != nums[l])
                    Max = max(Max,r-l+1);
                r++;
                }
            else l++;
           }
        return Max;
    }
};