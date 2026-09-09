#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int minR = grid.size(), maxR = -1, minC = grid[0].size(), maxC = -1;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] == 1){
                    minR = min(minR,i);
                    maxR = max(maxR,i);
                    minC = min(minC,j);
                    maxC = max(maxC,j);
                }
            }
        }
        return((maxR-minR+1)*(maxC-minC+1));
    }
};