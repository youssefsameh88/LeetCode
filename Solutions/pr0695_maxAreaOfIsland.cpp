#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int area = 0;
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int mx = 0;
        for(int x = 0; x < grid.size(); x++){
            for(int y = 0; y < grid[0].size(); y++){
                area = 0;
                if(grid[x][y]){
                    mx = max(mx, dfs(grid,x,y));
                }
            }
        }
        return mx;
    }
    int dfs(vector<vector<int>>& grid, int x, int y){
        if(x < 0 || y < 0 || x >= grid.size() || y >= grid[0].size() || !grid[x][y]) return 0;
        grid[x][y] = 0;
        dfs(grid,x+1,y);
        dfs(grid,x-1,y);
        dfs(grid,x,y+1);
        dfs(grid,x,y-1);
        area++;
        return area;
    }
};