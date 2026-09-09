#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int total = 0;
        for(int num : nums) total = (total + num) % p;
        if(!total) return 0;

        unordered_map<int,int> map;
        map[0] = -1;
        int ps = 0, minLen = -1;
        for(int i = 0; i < nums.size(); i++){
            ps = (ps + nums[i]) % p;
            if(map.count((ps - total + p)%p)){
                if(minLen == -1) minLen = i - map[(ps - total + p)%p];
                else minLen = min(minLen, i - map[(ps - total + p)%p]);
            }
            map[ps] = i;
        }
        return minLen == nums.size() ? -1 : minLen;
    }
};