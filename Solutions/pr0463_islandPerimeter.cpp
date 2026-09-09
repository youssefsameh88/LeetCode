#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int per = 0;
    int N, M;
    int islandPerimeter(vector<vector<int>>& grid) {
        bool stop = false;
        M = grid.size(), N = grid[0].size();
        vector<vector<bool>> vis(N,vector<bool>(M));
        for(int x = 0; x < M; x++){
            for(int y = 0; y < N; y++){
                if(grid[x][y]){
                dfs(grid,x,y,vis);
                stop = true;
                break;
                }
            }
            if(stop) break;
        }
        return per;
    }
    void dfs(vector<vector<int>>& grid, int x, int y,vector<vector<bool>>& vis){
        if(x < 0 || y < 0 || x >= M || 
        y >= N || !grid[x][y] || vis[x][y]) return;
        per += (x-1 < 0 || !grid[x-1][y]) + (x+1 >= M || !grid[x+1][y])
            +  (y-1 < 0 || !grid[x][y-1]) + (y+1 >= N || !grid[x][y+1]);
        vis[x][y] = true;
        dfs(grid,x+1,y,vis);
        dfs(grid,x-1,y,vis);
        dfs(grid,x,y+1,vis);
        dfs(grid,x,y-1,vis);
    }
};