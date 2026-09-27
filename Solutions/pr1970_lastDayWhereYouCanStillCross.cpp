#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int m, n;
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        m = row, n = col;
        int l = 0, r = cells.size(), ans = 0;
        while(l <= r){
            int mid = (l+r)/2;
            if(check(mid, cells)){
                ans = mid;
                l = mid + 1;
            }
            else r = mid - 1;
        }
        return ans;
    }

    bool check(int days, vector<vector<int>>& cells){
        vector<vector<bool>> vis(m,vector<bool>(n));
        for(int i = 0; i < days; i++) vis[cells[i][0]-1][cells[i][1]-1] = true;

        for(int j = 0; j < n; j++){
            if(dfs(cells, 0, j, vis)) return true;
        }
        return false;
    }

    bool dfs(vector<vector<int>>& cells, int i, int j, vector<vector<bool>>& vis){
        if(i < 0 || j < 0 || i >= m || j >= n || vis[i][j]) return false;
        if(i == m - 1) return true;
        vis[i][j] = true;
        return ((i-1) > 0 && dfs(cells, i-1, j, vis)) ||
            dfs(cells, i+1, j, vis) ||
            dfs(cells, i, j+1, vis) ||
            dfs(cells, i, j-1, vis);
    }
};
