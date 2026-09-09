#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        if(obstacleGrid[0][0] || obstacleGrid.back().back()) return 0;
        vector<vector<int>> grid(m, vector<int>(n));
        
        for(int i = 0; i < m; i++){
            if(obstacleGrid[i][0]) break;
            grid[i][0] = 1;
        }
        for(int i = 0; i < n; i++){
            if(obstacleGrid[0][i]) break;
            grid[0][i] = 1;
        }  
        
        for(int i = 1; i < grid.size(); i++){
            for(int j = 1; j < grid[0].size(); j++){
                    if(valid(i-1,j,obstacleGrid))
                        grid[i][j] += grid[i-1][j]; 
                    if(valid(i,j-1,obstacleGrid))
                        grid[i][j] += grid[i][j-1];
            }
        }
        return grid.back().back();
    }
    bool valid(int x, int y, vector<vector<int>>& g){
        return !g[x][y];
    }
};