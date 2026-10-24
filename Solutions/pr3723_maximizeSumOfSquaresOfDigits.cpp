#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        if(9*num < sum) return "";
        string ans(sum/9, '9');
        if(sum%9 > 0) ans += (char)(sum%9 + '0');
        ans.append(num-ans.size(), '0');
        return ans;
    }   
};
