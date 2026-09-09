#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximizeSum(vector<int>& nums, int k) {
        int n = *max_element(nums.begin(),nums.end());
        return k*(k+2*n-1)/2;
    }
};