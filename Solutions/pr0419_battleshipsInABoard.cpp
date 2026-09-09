#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        int m = board.size(), n = board[0].size(), count = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(board[i][j] == 'X'){
                    count++;
                    int x = i;
                    if(i < m-1 && board[i+1][j] == 'X')
                        while(x < m && board[x][j] == 'X') board[x++][j] = '.';
                    else{
                        x = j;
                        while(x < n && board[i][x] == 'X') board[i][x++] = '.';
                    }
                }
            }
        }
        return count;   
    }
};
