#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int total = 0;
        for(int size = 1; size <= min(matrix.size(), matrix[0].size()) ; size++){
            for(int i = 0; i < matrix.size(); i++){
                for(int j = 0; j < matrix[0].size(); j++){
                    if(check(matrix,i,j,size)) total++;
                }
            }
        }
        return total;
    }
    bool check(vector<vector<int>>& m, int i, int j, int size){
        if(size+i > m.size() || size+j > m[0].size()) return false;
        for(int r = i; r < i+size; r++){
            for(int c = j; c < j+size; c++){
                if(!m[r][c]) return false;
            }
        }
        return true;
    }
};