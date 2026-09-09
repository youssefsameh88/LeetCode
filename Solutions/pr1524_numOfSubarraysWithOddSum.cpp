#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int ps = 0;
        long long count = 0;
        vector<int> v(2);
        v[0]++;
        for(int i = 0; i < arr.size(); i++){
            ps+= arr[i];
            count += v[!(ps%2)];
            v[ps%2]++;
        }
        return count % (int)(1e9 + 7);
    }
};