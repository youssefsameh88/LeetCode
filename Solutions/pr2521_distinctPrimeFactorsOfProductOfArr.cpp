#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int distinctPrimeFactors(vector<int>& nums) {
        int n = nums.size();
        vector<bool> primes(1001, true);
        for(int i = 2; i*i <= 1001; i++){
            if(primes[i]) 
                for(int j = i*i; j <= 1001; j += i)
                    primes[j] = false;
        }
        unordered_set<int> factors;
        for(int i = 0; i < n; i++) {
                for(int j = 2; j <= nums[i]; j++){
                    if(primes[j] && nums[i] % j == 0){
                        factors.insert(j);
                    }
            }
        }
        return factors.size();
    }
};