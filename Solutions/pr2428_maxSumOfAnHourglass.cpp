#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSum(vector<vector<int>>& grid) {
        int ans = 0; 
        for(int i = 0; i < grid.size()-2; i++){
            for(int j = 1; j < grid[0].size()-1; j++){
                int hg = grid[i][j-1]+grid[i][j]+grid[i][j+1]+grid[i+1][j]+grid[i+2][j-1]+grid[i+2][j]+grid[i+2][j+1];
                ans = max(ans, hg);
            }
        }
        return ans;
    }
};
