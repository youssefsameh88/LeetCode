#include <bits/stdc++.h>
using namespace std;
int guess(int n);

class Solution {
public:
    int guessNumber(int n) {
        int l = 1, r = n;
        while(l <= r){
            int mid = l + (r-l)/2;
            int g = guess(mid);
            if(g > 0) l = mid + 1;
            else if(g < 0) r = mid - 1;
            else return mid;
        } 
        return -1;
    }
};