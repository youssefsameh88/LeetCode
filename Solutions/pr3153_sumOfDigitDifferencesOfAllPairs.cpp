#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long sumDigitDifferences(vector<int>& nums) {
        int size = 0, n = nums[0];
        while(n){
            size++;
            n /= 10;
        }
        vector<vector<int>> v(size, vector<int>(10));
        long long ans = 0;
        for(int i = 0; i < size; i++){
            for(int j = 0; j < nums.size(); j++){
                v[i][extract(nums[j], size-i-1)]++; 
            }
        }

        for (int i = 0; i < size; i++) {
            for (int j = 0; j < 10; j++) {
                long long x = v[i][j];
                ans += x * (nums.size() - x) ;
            }
        }
        return ans/2;
    }
    int extract(int num, int pos){
        return (int)(num/pow(10,pos))%10;
    }
};