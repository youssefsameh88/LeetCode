#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(), n2 = nums2.size();
        int mx = 0;
        for(int j = 0; j  < n2 ; j++){
            int limit = min(j+1, n1); 
            int i = upper_bound(nums1.begin(), nums1.begin()+limit , nums2[j], greater<int>()) - nums1.begin();
            if(i) i--;
            if(nums1[i] >= nums2[j])
            mx = max(mx, j - i);
        }
        return mx;
    }
};