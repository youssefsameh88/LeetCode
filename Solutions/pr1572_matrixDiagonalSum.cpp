#include <vector>
using namespace std;
class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int count = 0, s = mat.size();
        for(int i = 0; i < s ; i++) 
            count += mat[i][i] + mat[i][s-i-1];
        
        if(s % 2) count -= mat[s/2][s/2];
        return count;
    }
};