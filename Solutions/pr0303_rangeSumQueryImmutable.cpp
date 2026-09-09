#include <vector>
using namespace std;
class NumArray {
public:
    vector<int> v;
    NumArray(vector<int>& nums) {
        v.resize(nums.size() + 1);
        for(int i = 1; i <= nums.size(); i++){
            v[i] += v[i-1] + nums[i-1];
        }
    }
    
    int sumRange(int left, int right) {
        return v[right+1] - v[left];
    }
};
