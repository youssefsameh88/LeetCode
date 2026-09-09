#include <vector>
class Solution {
public:
    int singleNumber(std::vector<int>& nums) {
        int n = 0;
        for(int num : nums) n ^= num;
        return n;
    }
};
