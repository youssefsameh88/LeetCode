#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int sumOfTheDigitsOfHarshadNumber(int x) {
        int y = x, sum = 0;
        while(y){
            sum += y%10;
            y /=10;
        }
        return x%sum == 0 ? sum : -1;
    }
};