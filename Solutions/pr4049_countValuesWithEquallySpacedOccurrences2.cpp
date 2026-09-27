#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        map<int,vector<int>> map;
        for(int i = 0 ; i < nums.size(); i++){
            map[nums[i]].push_back(i);
        }
        int count = 0;
        for(auto& [num, idx] : map){
            if(idx.size() < 3) continue;
            int x = idx[1] - idx[0];
            bool flag = true;
            for(int i = 2; i < idx.size(); i++){
                if(idx[i] - idx[i-1] != x){
                    flag = false;
                    break;
                }
            }
            count += flag;
        }

        return count;
    }
};
