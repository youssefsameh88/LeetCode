#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        vector<int> v(m);
        if(!k) return grid;
        for(int i = 0; i < k; i++){
            for(int i = 0; i < m ; i++) v[i] = grid[i].back();
            for(int i = m - 1; i >= 0; i--){
                for(int j = n - 1; j > 0; j--){
                    grid[i][j] = grid[i][j-1];
                }
            }
            grid[0][0] = v.back();
            for(int i = 1; i < m; i++)
                grid[i][0] = v[i-1];
        }
        return grid;
    }
};
