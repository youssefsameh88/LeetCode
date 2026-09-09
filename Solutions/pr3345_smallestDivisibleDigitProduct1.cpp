#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int smallestNumber(int n, int t) {
        while(true){
            int x = n, mult = 1;
            while(x){
                mult *= (x%10);
                x /= 10;
            }
            if( mult % t == 0) return n;
            n++;
        }
    }
};