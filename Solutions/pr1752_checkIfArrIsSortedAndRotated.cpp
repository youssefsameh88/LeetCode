#include <vector>
using namespace std;

class Solution {
public:
    bool check(vector<int>& nums) {
        int c = 1, s = nums.size();
        if(s < 3) return true;
        for(int i = 0; i < s; i++){
            if(nums[i%s] > nums[(i+1)%s]) c--;
            if(c < 0) return false;
        }
        return true;
    }
};