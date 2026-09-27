#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        unordered_map<int,vector<int>> map;
        for(int i = 0 ; i < nums.size(); i++){
            map[nums[i]].push_back(i);
        }
        int count = 0;
        for(auto& [num, idx] : map){
            if(idx.size() != 3) continue;
            if(idx[1] - idx[0] == idx[2] - idx[1]) count++;
        }

        return count;
    }
};
