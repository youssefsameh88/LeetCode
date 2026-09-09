#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int p = INT_MIN;
        for(int i = 2; i >=-1; i--)
            p = max(p, nums[((i%n)+n)%n]*nums[(((i-1)%n)+n)%n]*nums[(((i-2)%n)+n)%n]);
        
        return p;
    }
};
