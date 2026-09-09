#include <iostream>
#include <cmath>
using namespace std;
class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n <= 0) return false;
        if(n == 1) return true;
         int mult = 1;
        int limit = pow(2,31)/3 + 1;
        while(mult < n && mult < limit){
            mult *= 3;
            if(mult == n) return true;
        }
        return false;
    }
};