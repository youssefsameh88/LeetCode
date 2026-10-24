#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        int less = 0, eq = 0;
        for(int num : nums) 
            if(num < target) less++;
            else if(num == target) eq++;
       vector<int> v(eq);
       iota(v.begin(),v.end(),less);
       return v;
    }
};
