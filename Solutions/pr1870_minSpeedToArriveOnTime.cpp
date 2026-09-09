#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minSpeedOnTime(vector<int>& dist, double hour) {
        if(ceil(hour) < dist.size()) return -1;
        int l = 1, r = 1e7, ans = 0;
        while(l <= r){
            int mid = (l+r)/2;
            if(ok(mid, hour, dist)){
                ans = mid;
                r = mid - 1;
            }
            else{
                l = mid + 1;
            }
        }
    return ans;
    }
    bool ok(int mid, double hour, vector<int>& v){
        double sum = 0;
        int n = v.size() - 1;
        for(int i = 0; i < n; i++){
                sum += ceil((double)v[i]/mid);
                if((double)sum > hour) return false;
        }
        return sum + (double)v.back()/mid <= hour;
    }
};