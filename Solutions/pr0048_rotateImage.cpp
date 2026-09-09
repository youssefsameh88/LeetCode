#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        helper(matrix,0);
        for(int i = 0; i < matrix.size() ; i++){
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
    void helper(vector<vector<int>>& m, int n){
        if(n >= m.size()) return;
        for(int i = n+1 ; i < m.size(); i++){
            swap(m[n][i],m[i][n]);
        }
        helper(m, n+1);
    }
};