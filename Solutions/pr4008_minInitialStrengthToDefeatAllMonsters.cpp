#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long minInitialStrength(vector<int>& monsters, vector<vector<int>>& boosts) {
        vector<long long> v(monsters.size()+1);
        for(int i = 0; i < boosts.size(); i++){
            v[boosts[i][0]] += boosts[i][2];
            v[boosts[i][1]+1] -= boosts[i][2];
        }
        for(int i = 1; i < v.size(); i++) v[i] += v[i-1];

        long long l = 0, r = 5e14, ans = 0;
        while(l <= r){
            long long mid = (l+r)/2;
            if(check(mid, monsters, v)){
                ans = mid;
                r = mid-1;
            }
            else l = mid+1;
        }
        return ans;
    }
    bool check(long long mid, vector<int>& m, vector<long long>& v){
        for(int i = 0; i < m.size(); i++){
            if(mid + v[i] < m[i]) return false;
            mid -= m[i];
            if(mid < 0) mid = 0;
        }
        return true;
    }
};
