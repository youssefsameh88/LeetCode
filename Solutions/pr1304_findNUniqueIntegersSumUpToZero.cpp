#include <vector>
using namespace std;
class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> v;
        for(int i = - (n/2); i <= n/2 ; i++){
            if(i) v.push_back(i);
        }
        if(n%2) v.push_back(0);
        return v;
    }
};