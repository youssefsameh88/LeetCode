#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<string>> ans;
    int N;
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n,string(n,'.'));
        N = n;
        helper(board,0);
        return ans;
    }
    void helper(vector<string>& board,int row){
        if(row == N){
            ans.push_back(board);
            return;
        }
        for(int i = 0; i < N; i++){
            if(check(board,row,i)){
                board[row][i] = 'Q';
                helper(board,row+1);
                board[row][i] = '.';
            }
        }
    }
    bool check(vector<string>& board, int x, int y){
        for(int i = 0; i < N; i++){
            if(board[i][y] == 'Q') return false;
        }
        for(int i = 0; x-i >= 0 && y-i >= 0; i++){
            if(board[x-i][y-i] == 'Q') return false;
        }
        for(int i = 0; x-i >= 0 && i+y < N; i++){
            if(board[x-i][y+i] == 'Q') return false;
        }
        return true;
    }
};