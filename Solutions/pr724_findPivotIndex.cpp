#include <vector>
using namespace std;

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        vector<int> ps(nums.size()+1);
        for(int i = 1 ; i <= nums.size(); i++){
            ps[i] = ps[i-1] + nums[i-1];
        }
        for(int i = 0; i < nums.size(); i++){
            if(ps[i] == ps.back() - ps[i+1]) return i;
        }
        return -1;
    }
};
