#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long minimumTime(vector<int>& time, int totalTrips) {
        long long l = 1, r = 1e18, ans = 0;
        while(l <= r){
            long long mid = l + (r-l)/2;
            long long sum = 0;
            for(int num : time) {
                sum += mid / num;
                if(sum >= totalTrips) break;
                }
            if(sum >= totalTrips){
                ans = mid;
                r = mid - 1;
            }
            else {
                l = mid + 1;
            }
        }
        return ans;
    }
};