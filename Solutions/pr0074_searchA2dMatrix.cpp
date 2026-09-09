#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int l = 0, r = matrix.size() - 1, row = 0, m = 0;
        while(l <= r){
             m = (l+r)/2;
            if(matrix[m][0] > target) r = m - 1; 
            else if(matrix[m][0] < target){
                row = m;
                l = m + 1;
            }
            else return true;
        }
      return binary_search(matrix[row].begin(), matrix[row].end(), target);
    }
};