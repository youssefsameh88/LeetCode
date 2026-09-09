#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i = 0; i < 9; i++){
            set<char> s;
            for(int j = 0; j < 9; j++){
                if(board[i][j] == '.') continue;
                if(s.count(board[i][j])){
                    return false;
                }
                s.insert(board[i][j]);
            }
        }   


        for(int i = 0; i < 9; i++){
            set<char> s;
            for(int j = 0; j < 9; j++){
                if(board[j][i] == '.') continue;
                if(s.count(board[j][i])){
                    return false;
                }
                s.insert(board[j][i]);
            }
        } 
        
        for(int i = 0; i < 9; i+=3){
            for(int j = 0; j < 9; j+=3){
                set<char> s;
                for(int k = 0; k < 3; k++){
                    for(int l = 0; l < 3; l++){
                        if(board[k+i][l+j] == '.') continue;
                        if(s.count(board[k+i][l+j])){
                            return false;
                        }
                        s.insert(board[k+i][l+j]);
                    }
                }
            }
        }
        return true;
    }
};

