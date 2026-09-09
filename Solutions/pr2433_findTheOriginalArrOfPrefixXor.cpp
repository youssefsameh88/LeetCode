#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        vector<int> ans(pref.size());
        for(int i = 1; i < pref.size(); i++)
            ans[i] = pref[i] ^ pref[i-1];
        
        ans[0] = pref[0];
        return ans;
    }
};