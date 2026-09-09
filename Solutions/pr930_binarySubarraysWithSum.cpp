#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int ps = 0, count = 0;
        unordered_map<int, int> map;
        map[0] = 1;
        for(int i = 0; i < nums.size(); i++){
            ps += nums[i];
            count += map[ps - goal];
            map[ps]++;
        }
        return count;
    }
};