#include <vector>
using namespace std;
class Solution {
public:
    int tribonacci(int n) {
        vector<int> v(3);
        v[1] = v[2] = 1;
        for(int i = 3; i <= n ; i++){
            v.push_back(v[i-1] + v[i-2] + v[i-3]);
        }
        return v[n];
    }
};