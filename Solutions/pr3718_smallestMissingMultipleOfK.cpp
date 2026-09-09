#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        int n = k;
        unordered_set<int> set(nums.begin(), nums.end());
        for(int i = 0; i < set.size(); i++){
            if(!set.count(n)) return n;
            n += k;
        }
        return n;
    }
};
