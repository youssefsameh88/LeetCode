#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int m, n; 
    int getMaximumGold(vector<vector<int>>& grid) {
        m = grid.size(), n = grid[0].size();
        int count = 0;
        vector<vector<bool>> vis(m, vector<bool>(n));
            for(int i = 0; i < m; i++){
                for(int j = 0; j < n; j++){
                    if(grid[i][j])
                        count = max(count, helper(grid,i,j,vis));
                }
            }
            return count;
    }
    int helper(vector<vector<int>>& grid, int x, int y, vector<vector<bool>>& vis){
        if(x >= m || y >= n || x < 0 || y < 0 || vis[x][y] || !grid[x][y]) 
            return 0;
        vis[x][y] = true;
        int a = helper(grid, x+1, y, vis);
        int b = helper(grid, x-1, y, vis);
        int c = helper(grid, x, y+1, vis);
        int d = helper(grid, x, y-1, vis);
        vis[x][y] = false;
        return max({a, b, c, d}) + grid[x][y];
    }
};