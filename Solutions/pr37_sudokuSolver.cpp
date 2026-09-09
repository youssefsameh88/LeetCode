#include <bits/stdc++.h>
using namespace std;

#define allv unordered_set<int>(v.begin(),v.end())
class Solution {
public:
    vector<vector<char>> b;
    void solveSudoku(vector<vector<char>>& board) {
        vector<int> v = {1,2,3,4,5,6,7,8,9};
        vector<vector<unordered_set<int>>> minimats(3,vector<unordered_set<int>>(3,allv));
        vector<unordered_set<int>> col(9,allv);
        vector<unordered_set<int>> row(9,allv);
        int totalNums = 0;

        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                if(board[i][j] == '.') continue;
                minimats[i/3][j/3].erase(board[i][j]-'0');
                row[i].erase(board[i][j]-'0');
                col[j].erase(board[i][j]-'0');
                totalNums++;
            }
        }
            helper(board,minimats,row,col,0,0,totalNums);
    }

    bool helper(vector<vector<char>>& board,vector<vector<unordered_set<int>>>& minimats,
    vector<unordered_set<int>>& row, vector<unordered_set<int>>& col, int i, int j, int totalNums){
        if(i == 8 && j == 9) return totalNums == 81;
        if(j == 9) return helper(board,minimats,row,col,i+1,0,totalNums);
        if(board[i][j] != '.') return helper(board,minimats,row,col,i,j+1,totalNums);

        for(int k = 1; k < 10; k++){
            if(!minimats[i/3][j/3].count(k) || !row[i].count(k) || !col[j].count(k)) continue;
            board[i][j] = k+'0';
            minimats[i/3][j/3].erase(k);
            row[i].erase(k);
            col[j].erase(k);

            if(helper(board,minimats,row,col,i,j+1,totalNums+1)) return true;

            minimats[i/3][j/3].insert(k);
            row[i].insert(k);
            col[j].insert(k);
            board[i][j] = '.';
        }
        return false;
    }
};