#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool xorGame(vector<int>& nums) {
        int xr = 0;
        for(int i = 0; i < nums.size(); i++) xr ^= nums[i];
        if(xr){
            return !(nums.size()%2);
        }
        else return true;
    }
};
