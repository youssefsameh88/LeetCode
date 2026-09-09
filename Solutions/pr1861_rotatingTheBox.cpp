#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& boxGrid) {
        int m = boxGrid.size(), n = boxGrid[0].size();
        for(int i = 0; i < m ; i++){
            int j = 0;
            while(j < n){
                int stones = 0;
                while(j < n && boxGrid[i][j] == '*') j++;
                while(j < n && boxGrid[i][j] != '*'){
                    if(boxGrid[i][j] == '#'){
                        stones++;
                        boxGrid[i][j] = '.';
                    }
                    j++;
                }
                int k = j - 1;
                while(stones > 0){
                    boxGrid[i][k] = '#';
                    k--;
                    stones--;
                }
            }
        }
        vector<vector<char>> v(n,vector<char>(m));
        for(int i = 0 ; i < m ; i++){
            for(int j = 0; j < n ; j++){
                v[j][m-i-1] = boxGrid[i][j];
            }
        }
        return v;
    }
};