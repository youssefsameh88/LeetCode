#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int reached = 0;
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size(), total = 0;
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
                if(grid[i][j]) total++;

        for(int i = 0; i < m; i++){
            if(grid[i][0])
                dfs(grid,i,0);
            if(grid[i][n-1])
                dfs(grid,i,n-1);
        }
        for(int i = 0; i < n; i++){
            if(grid[0][i])
                dfs(grid,0,i);
            if(grid[m-1][i])
                dfs(grid,m-1,i);
        }
        return total - reached;
    }
    void dfs(vector<vector<int>>& grid, int x, int y){
        if(x < 0 || y < 0 || x >= grid.size() || 
        y >= grid[0].size() || !grid[x][y]) return;

        grid[x][y] = 0;
        dfs(grid,x+1,y);
        dfs(grid,x-1,y);
        dfs(grid,x,y+1);
        dfs(grid,x,y-1);
        reached++;
    }
};