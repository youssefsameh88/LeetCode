#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int l = *max_element(weights.begin(),weights.end()), r = 3e7, ans = -1;
        while(l <= r){
            int mid = l + (r-l)/2;
            if(check(weights, mid,days)){
                ans = mid;
                r = mid - 1;
            }
            else l = mid + 1;
        }
        return ans;
    }
    bool check(vector<int>& w, int c, int days){
        int d = 1, cap = 0;
        for(int i = 0; i < w.size(); i++){
            if(cap + w[i] <= c){
                cap += w[i];
            }
            else{
                d++;
                cap = w[i];
            }
        }
        return d <= days;
    }
};