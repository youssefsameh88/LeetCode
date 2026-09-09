#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long minOperationsToMakeMedianK(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int mid = nums.size()/2;
        long long  op = 0;
        if(nums[mid] == k) return 0;
        
        if(nums[mid] < k) {
            for(int i = mid; i < nums.size(); i++) 
                if(nums[i] < k) op += abs(k-nums[i]);
        }
        else 
            for(int i = 0; i <= mid; i++) 
            if(nums[i] > k) op += abs(k-nums[i]);
        return op;
    }
};