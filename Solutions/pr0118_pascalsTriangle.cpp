#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        numRows--;
        vector<vector<int>> v;
        int i = 1;
        v.push_back({1});
        while(numRows--){
            v.push_back({1});
            for(int j = 1 ; j < v[i-1].size() ; j++){
                v[i].push_back(v[i-1][j] + v[i-1][j-1]);
            }
            v[i].push_back(1);
            i++;
        }
        return v;
    }
};