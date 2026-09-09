#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        vector<int> freq(value);
        for(int num : nums){
            freq[((num%value)+value)%value]++;
        }
        int mex = 0;
        while(freq[mex%value]){
            if(!freq[mex%value]) return mex;
            freq[mex%value]--;
            mex++;
        }
        return mex;
    }
};