#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int mx = 0, n = nums.size();
        vector<int> v(n);
        for(int i = 0; i < n; i++){
            mx = max(mx,nums[i]);
            v[i] = gcd(nums[i],mx);
        }
        sort(v.begin(),v.end());
        long long sum = 0;
        for(int i = 0; i < n/2; i++){
            sum += gcd(v[i], v[n-i-1]);
        }
        return sum;
    }
};