#include <vector>
using namespace std;

class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> ans;
        ans.reserve(nums.size());
        int count = 0;
        for(int num : nums){
            if(num == pivot) count++;
            if(num < pivot) ans.push_back(num);
        }
        while(count-- > 0)ans.push_back(pivot);
        for(int num : nums)
            if(num > pivot) ans.push_back(num);
        
        return ans;
    }
};
