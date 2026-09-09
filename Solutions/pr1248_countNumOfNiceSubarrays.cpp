#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int ps = 0, count = 0;
        unordered_map<int,int> map;
        map[0] = 1;
        for(int i = 0; i < nums.size(); i++){
            ps += nums[i] % 2;
            count += map[ps - k];
            map[ps]++;
        }
        return count;
    }
};