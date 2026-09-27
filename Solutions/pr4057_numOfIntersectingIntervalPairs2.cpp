#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long countIntersectingIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](vector<int>& a, vector<int>& b){
           if(a[0] != b[0]) return a[0] < b[0];
            return a[1] > b[1];
        });
        long long ans = 0;
        for(int i = 0; i < intervals.size(); i++){
            int l = i, r = intervals.size()-1, add = 0;
            while(l <= r){
                int mid = (l+r)/2;
                if(intervals[i][1] >= intervals[mid][0]){
                    add = mid;
                    l = mid + 1;
                }
                else r = mid - 1;
            }
            ans += add-i;
        }
        return ans;
    }
};
