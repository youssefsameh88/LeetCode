#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int> pxor(arr.size() + 1);
        int count = 0;
        for(int i = 0; i < arr.size(); i++){
            count ^= arr[i];
            pxor[i+1] =  count;
        }
        vector<int> ans(queries.size());
        for(int i = 0 ; i < queries.size(); i++){
            ans[i] = pxor[queries[i][0]] ^ pxor[queries[i][1]+1];
        }
        return ans;
    }
};