#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<vector<int>> v(n, vector<int>(2));
        int ans = 0;
        for(int i = 1; i < n-1; i++){
            v[i][0] = max(v[i-1][0], height[i-1]);
            v[n-i-1][1] = max(v[n-i][1], height[n-i]);
        }
        for(int i = 1; i < n-1; i++)
            ans += max(0, min(v[i][0], v[i][1]) - height[i]);
        return ans;
    }
};
