#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int m, n;
    string w;
    vector<vector<char>> b;
    bool exist(vector<vector<char>>& board, string word) {
        m = board.size();
        n = board[0].size();
        w = word;
        b = board;
        vector<vector<bool>> vis(m,vector<bool>(n));
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                string s = "";
                if(b[i][j] == w[0]) 
                    if(helper(s,i,j,vis))
                        return true;
            }
        }
        return false;
    }
    bool helper(string& s, int x, int y,vector<vector<bool>>& vis){
        if(s.size() == w.size()) return s == w;
        if(x < 0 || y < 0 || x >= m || y >= n || vis[x][y]) return false;

        vis[x][y] = true;
        s += b[x][y];
        bool a = helper(s, x+1, y,vis);
        bool b = helper(s, x-1, y,vis);
        bool c = helper(s, x, y+1,vis);
        bool d = helper(s, x, y-1,vis);
        vis[x][y] = false;
        s.pop_back();
        return a || b || c || d;
    }
};