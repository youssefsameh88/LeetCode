#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        pair<int,int> p = {0,0};
        for(int i = 0; i < nums.size(); i++){
            if(!p.second) p.first = nums[i];
            if(nums[i] == p.first) p.second++;
            else p.second--;
        }
        return p.first;
    }
};