#include <vector>
using namespace std;
class Solution {
public:
    vector<int> getNoZeroIntegers(int n) {
       for(int i = 1; i < n ; i++){
        if(noZero(i) && noZero(n - i)) return {i , n - i};
       }
       return {};
    }
    bool noZero(int x){
        while(x){
            if(x%10 == 0) return false;
            x /= 10;
        }
        return true;
    }
};