#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
        int n = nums.size();
        vector<int> ps(n+2);
        for(int i = 0; i < n; i++){
            ps[i+1] = ps[i] + nums[i];
        }
        for(int i = 0; i < n; i++){
            if(ps[n] - ps[i+1] == ps[i])
                return i;
        }
        return -1;
    }
};