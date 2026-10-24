#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        vector<vector<int>> ps(mat.size()+1, vector<int>(mat[0].size()+1));
        for(int i = 1; i < ps.size(); i++){
            for(int j = 1; j < ps[0].size(); j++){
                ps[i][j] = mat[i-1][j-1] + ps[i-1][j] + ps[i][j-1] - ps[i-1][j-1];
            }
        }
        for(int i = 1; i < ps.size(); i++){
            for(int j = 1; j < ps[0].size(); j++){
                int x1 = max(1, i-k), x2 = min(i+k, (int)mat.size());
                int y1 = max(1, j-k), y2 = min(j+k, (int)mat[0].size());
                mat[i-1][j-1] = ps[x2][y2] - ps[x1-1][y2] - ps[x2][y1-1] + ps[x1-1][y1-1];
            }
        } 
        return mat;
    }
};