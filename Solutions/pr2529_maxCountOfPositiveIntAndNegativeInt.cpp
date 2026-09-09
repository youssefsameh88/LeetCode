#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumCount(vector<int>& nums) {
        auto neg = upper_bound(nums.begin(), nums.end(),-1);
        auto pos = upper_bound(nums.begin(), nums.end(),0);
        return max((int) (neg - nums.begin()), (int)(nums.end() - pos));
    }
};