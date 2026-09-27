#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        sort(arr.begin(), arr.end(), [&](int a, int b){
            if(abs(a-x) != abs(b-x)) return abs(a-x) < abs(b-x);
            return a < b;
        });
        arr.resize(k);
        sort(arr.begin(), arr.end());
        return arr;
    }
};
