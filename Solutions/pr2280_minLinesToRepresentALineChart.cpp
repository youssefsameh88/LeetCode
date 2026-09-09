#include <bits/stdc++.h>
using namespace std;

#define ll long long
class Solution {
public:
    int minimumLines(vector<vector<int>>& sp) {
        if(sp.size() == 1) return 0;
        sort(sp.begin(),sp.end());
        int count = 1;
        for(int i = 2; i < sp.size(); i++){
            ll dx1 = sp[i][0] - sp[i-1][0], dx2 = sp[i-1][0] - sp[i-2][0];
            ll dy1 = sp[i][1] - sp[i-1][1], dy2 = sp[i-1][1] - sp[i-2][1];
            if(dy1 * dx2 != dy2 * dx1) count++;
        }
        return count;
    }

};
