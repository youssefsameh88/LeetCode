#include <vector>
using namespace std;
class Solution {
public:
    int minimumPrefixLength(vector<int>& nums) {
        int i = nums.size() - 1;
        for(; i > 0 ; i--)
            if(nums[i] <= nums[i-1]) break;
        
        return i;
    }
};
