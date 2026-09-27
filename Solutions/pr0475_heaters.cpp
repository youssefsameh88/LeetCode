#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findRadius(vector<int>& hs, vector<int>& ht) {
        sort(ht.begin(), ht.end());
        int l = 0, r = 1e9 + 1, ans = 0;
        while(l <= r){
            int mid = l + (r-l)/2;
            if(check(mid, hs, ht)){
                ans = mid;
                r = mid - 1;
            }
            else l = mid + 1;
        }
        return ans;
    }
    bool check(int radius, vector<int>& hs, vector<int>& ht){
        for(int i = 0; i < hs.size(); i++){
            int m = lower_bound(ht.begin(),ht.end(),hs[i]) - ht.begin(), dist = 0;
            if(m == ht.size()) dist = abs(ht[m-1]- hs[i]);
            else if(!m) dist = abs(ht[m] - hs[i]);
            else dist = min(abs(ht[m] - hs[i]) , abs(ht[m-1] - hs[i]));
                
            if(radius < dist) return false;
        }
        return true;
    }
};