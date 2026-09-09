#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        int y = grid[0][0]%x;
        vector<int> v;
        for(int i = 0; i < grid.size(); i++)
            for(int j = 0; j < grid[i].size(); j++){
                if(y != grid[i][j]%x) return -1;
                v.push_back(grid[i][j]);
            }
        sort(v.begin(),v.end());
        int median = v[v.size()/2];
        int op = 0;
        for(int i = 0; i < v.size(); i++)
            op += abs(v[i] - median)/x;
        
        return op;
    }
};
