#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        if((long long)m*k > bloomDay.size()) return -1;
        auto [mn, mx] = minmax_element(bloomDay.begin(), bloomDay.end());
        int l = *mn, r = *mx, ans = *mn;
        while(l <= r){
            int mid = (l+r)/2;
            if(ok(mid, m, k-1, bloomDay)){
                ans = mid;
                r = mid - 1;
            }
            else {
                l = mid + 1;
            }
        }
        return ans;
    }
    bool ok(int day, int m,int k, vector<int>& nums){
        int cnt = 0, bq = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] <= day){
                if(cnt != k) cnt++;
                else {
                    bq++;
                    cnt = 0;
                }
            }
            else cnt = 0;
        }
        return bq >= m;
    }
};
