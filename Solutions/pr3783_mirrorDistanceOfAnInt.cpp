#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int mirrorDistance(int n) {
        int m = n;
        long long num = 0;
        while(n && n%10 == 0) n /= 10;
        while(n){
            num += n%10;
            num *= 10;
            n /= 10;
        }
        num /= 10;
        return  abs(m-num);
    }
};