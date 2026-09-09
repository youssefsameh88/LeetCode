#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canAliceWin(int n) {
        bool win = true;
        int s = 10;
        while(n >= 0){
            if(n < s) return !win;
            n -= s;
            s--;
            win = !win;
        }
        return win;
    }
};