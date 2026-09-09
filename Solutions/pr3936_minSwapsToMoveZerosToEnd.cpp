#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumSwaps(vector<int>& nums) {
        int c = 0, n = nums.size();
        for(int i = 0; i < n; i++) if(!nums[i]) c++;
        int c1 = c;
        for(int i = n-1; i >= n - c1; i--) if(!nums[i]) c--;
        
        return c;
    }
};