#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> v;
        for(int i = nums.size()-1 ; i >= 0; i--){
            while(nums[i] > 0){
                v.push_back(nums[i]%10);
                nums[i] /= 10;
            }
        }
        reverse(v.begin(),v.end());
        return v;
    }
};