#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int rotatedDigits(int n) {
        int count = 0;
        for(int i = 1; i <= n; i++){
            bool valid = true, changed = false;
            int k = i;
            while(k){
                int x = k%10;
                if(x == 3 || x == 4 || x == 7){
                    valid = false;
                    break;
                }
                else if (x == 2 || x == 5 || x == 6 || x == 9) changed = true;
                k /= 10;
            }
            count += valid && changed;
        }
        return count;
    }
};