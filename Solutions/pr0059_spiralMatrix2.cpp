#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> v(n,vector<int>(n,-1));
        int  maxRow = n-1, minRow = 0;
        int  maxCol = n-1, minCol = 0;
        int i = 0, j = 0;
        int maxNum = n * n;
        for(int k = 1; k <= maxNum ; k++){
                v[i][j] = k;
            if(i == minRow && j < maxCol){
                j++;
                if(j == maxCol)
                    minRow++;
            }
            else if(i < maxRow && j == maxCol){
                i++;
                if(i == maxRow)
                    maxCol--;
            }
            else if(i == maxRow && j > minCol){
                j--;
                if(j == minCol)
                    maxRow--;
            }
            else if(i > minRow && j == minCol){
                i--;
                if(i == minRow)
                    minCol++;
            }
        }
      return v;
    }
};