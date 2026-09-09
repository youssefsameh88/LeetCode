#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int ps = 0, count = 0;
        unordered_map<int,int> map;
        map[0] = 1;
        for(int i = 0; i < nums.size(); i++){
            ps = ((ps + nums[i])%k + k ) % k;
            map[ps]++;
        }
        for(auto& [a,b] : map){
            count += (b * (b-1))/2;
        }
        return count;

    }
};
