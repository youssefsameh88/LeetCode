#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minAddToMakeValid(string s) {
        int d = 0, ans = 0;
        for(char& c : s){
            if(c == '(') d++;
            else d--;
            if(d == -1){
                d++;
                ans++;
            } 
        }
        return ans += d;
    }
};
