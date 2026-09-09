#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int m, n, st = 0;
    int uniquePathsIII(vector<vector<int>>& grid) {
        m = grid.size(), n = grid[0].size();
        int steps = 0, row = 0, col = 0;

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(!grid[i][j]) steps++;
                if(grid[i][j] == 1){
                    row = i;
                    col = j;
                }
            }
        }
        st = steps + 2;
        return helper(grid,row,col,1);
    }

    int helper(vector<vector<int>>& grid, int x, int y, int steps){
        if(x < 0 || y < 0 || x >= m || y >= n || grid[x][y] == -1) return 0;
        if(grid[x][y] == 2) return steps == st ? 1 : 0;

        grid[x][y] = -1;
        int a = helper(grid,x+1,y,steps+1);
        int b = helper(grid,x-1,y,steps+1);
        int c = helper(grid,x,y+1,steps+1);
        int d = helper(grid,x,y-1,steps+1);
        grid[x][y] = 0;
        return a + b + c + d;
    }
};