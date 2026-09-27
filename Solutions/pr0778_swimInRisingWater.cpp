#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int n;
    int swimInWater(vector<vector<int>>& grid) {
        int mx = -1;
        for(auto& v : grid) for(int num : v) mx = max(mx, num);
        n = grid.size();
        int l = grid[0][0], r = mx, ans = 0;
        while(l <= r){
            int mid = (l+r)/2;
            vector<vector<bool>> vis(n,vector<bool>(n));
            if(check(mid, grid, 0, 0, vis)){
                ans = mid;
                r = mid - 1;
            }
            else l = mid + 1;
        }
        return ans;
    }

    bool check(int time, vector<vector<int>>& grid, int i, int j, vector<vector<bool>>& vis){
        if(i >= n || j >= n || i < 0 || j < 0 || vis[i][j]) return false;
        if(grid[i][j] > time) return false;
        if(i == n - 1 && j == i) return true;

        vis[i][j] = true;
        return  check(time, grid, i-1, j, vis)
        || check(time, grid, i+1, j, vis)
        || check(time, grid, i, j-1, vis)
        || check(time, grid, i, j+1, vis);
    }
};
