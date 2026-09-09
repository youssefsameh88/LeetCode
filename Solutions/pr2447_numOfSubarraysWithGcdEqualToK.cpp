#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int subarrayGCD(vector<int>& nums, int k) {
        int count = 0;
        for(int i = 0; i < nums.size(); i++){
            int GCD = 0;
            for(int j = i; j < nums.size(); j++){
                GCD = gcd(GCD,nums[j]);
                if(GCD == k)count++;
            }
        }
        return count;
    }
};