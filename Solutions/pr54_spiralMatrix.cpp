#include <vector>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        
        int maxRow = matrix.size()-1, maxCol = matrix[0].size()-1;
        int minRow = 0, minCol = 0;
        int i = 0, j = 0;
        int size = (maxRow + 1) * (maxCol + 1);
        vector <int> nums;
        while(nums.size() < size){
            
            if(i == minRow && j < maxCol){
               for(; j <= maxCol ; j++) nums.push_back(matrix[i][j]);
               j--, i++, minRow++;
            }
            else if(i < maxRow && j == maxCol){
                for(; i <= maxRow ; i++) nums.push_back(matrix[i][j]);
                i--, j--, maxCol--;
            }
            else if(i == maxRow && j > minCol){
                for(; j >= minCol ; j--) nums.push_back(matrix[i][j]);
                i--, j++, maxRow--;
            }
            else if(i > minRow && j == minCol){
                for(; i >= minRow ; i--) nums.push_back(matrix[i][j]);
                j++,i++,minCol++;
            }
            else {
                nums.push_back(matrix[0][0]) ;
            }
        }
        return nums;
    }
};