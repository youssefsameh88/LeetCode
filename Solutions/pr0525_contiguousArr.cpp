#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        for(int& num : nums){
            num -= !num;
        }
        int ps = 0, maxLen = 0;
        unordered_map<int,int> map;
        map[0] = -1;
        for(int i = 0; i < nums.size() ; i++){
            ps += nums[i];
            if(!map.count(ps))
                map[ps] = i;
            else 
                maxLen = max(maxLen, i - map[ps]);
        }
        return maxLen;
    }
};