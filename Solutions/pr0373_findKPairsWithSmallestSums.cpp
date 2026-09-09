#include <bits/stdc++.h>
using namespace std;

#define pii pair<int,int>
class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        vector<vector<int>> ans;
        for(int i = 0; i < nums1.size(); i++){
            pq.push({nums1[i]+nums2[0] , 0});
        }

        while(k-- && !pq.empty()){
            pii p1 = pq.top();
            int s = p1.first, idx = p1.second;
            pq.pop();
            if(idx+1< nums2.size()) pq.push({s - nums2[idx]+nums2[idx+1], idx+1});
            ans.push_back({s-nums2[idx], nums2[idx]});
        }
        return ans;
    }
};