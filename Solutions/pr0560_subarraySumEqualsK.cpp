#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        vector<int> ps(nums.size() + 1);
        unordered_map<int,int> map;
        for(int i = 1; i <= nums.size(); i++){
            ps[i] = ps[i-1] + nums[i-1];
        }
        int ans = 0;
        for(int i = 0; i <= nums.size(); i++){
            ans += map[ps[i] - k];
            map[ps[i]]++;   
        }
        return ans;
    }
};