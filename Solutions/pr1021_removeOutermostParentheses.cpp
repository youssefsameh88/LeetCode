#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans;
        int d = 0;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '('){
                if(d > 0) ans += '(';
                d++;
            }
            else{
                if(d > 1) ans += ')';
                d--;
            }
        }
        return ans;
    }
};
