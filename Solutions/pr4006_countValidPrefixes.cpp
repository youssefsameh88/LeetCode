#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countValidPrefixes(string s) {
        int zc = 0, oc = 0, count = 0;
        for(char c : s){
            c == '1' ? oc++ : zc++;
            if(abs(zc-oc) <= 1) count++;
        }
        return count;
    }
};