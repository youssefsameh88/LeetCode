#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:

    bool checkSubarraySum(vector<int>& nums, int k) {
        if(nums.size() < 2) return false;
        vector<int> ps(nums.size() + 1);
        unordered_map<int,int> map;
        map[0] = -1;
        for(int i = 1; i <= nums.size(); i++){
            ps[i] = (ps[i-1] + nums[i-1]) % k;
        }
        for(int i = 0; i < nums.size(); i++){
            if (map.count( ps[i + 1])) {
                if (i - map[ps[i + 1]] >= 2)
                    return true;
            } 
            else map[ps[i + 1]] = i;
        }
        return false;
    }
};