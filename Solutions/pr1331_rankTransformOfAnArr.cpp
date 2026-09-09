#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> v(arr.begin(),arr.end());
        sort(v.begin(),v.end());
        v.erase(unique(v.begin(),v.end()),v.end());
        vector<int> ans(arr.size());
        for(int i = 0; i < arr.size(); i++){
            ans[i] = lower_bound(v.begin(),v.end(),arr[i]) - v.begin() + 1;
        }
        return ans;
    }
};
