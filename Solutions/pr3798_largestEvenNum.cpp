#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string largestEven(string s) {
        int r = s.size()-1;
        while(r >=0 && (s[r]-'0')%2) r--;
        return r == -1 ? "" : s.substr(0,r+1);
    }
};