#include <vector>
using namespace std;

class Solution {
public:
    vector<int> concatWithReverse(vector<int>& nums) {
        int n = nums.size();
        while(n > 0) nums.push_back(nums[--n]);
        return nums;
    }
};
