#include <iostream>
using namespace std;
class Solution {
public:
    bool isPerfectSquare(int num) {
        int l = 1, r = min(1 << 16 , num);
        while(l <= r){
            int m = l+(r-l)/2;
            cout << m << " ";
            long  x = (long)m * m;
            if(x > num) r = m - 1;
            else if(x < num) l = m + 1;
            else return true;
        }
        return false;
    }
};