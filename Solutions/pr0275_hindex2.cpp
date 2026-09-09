#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int hIndex(vector<int>& c) {
        int l = 0, r = c.size()-1, ans = 0;
        while(l <= r){
            int m = (l+r)/2;
            if(c[m] >= c.size()-m){
                ans = c.size() - m;
                r = m - 1;
            }
            else l = m + 1;
        }
        return ans;
    }
};