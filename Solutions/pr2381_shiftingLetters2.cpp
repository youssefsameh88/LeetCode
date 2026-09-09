#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        vector<int> v(s.size()+1);
        for(int i = 0; i < shifts.size(); i++){
            int sign = shifts[i][2] ? 1 : -1;
            v[shifts[i][0]] +=  sign;
            v[shifts[i][1]+1] -=  sign;
        }
        int count = 0;
        for(int i = 0; i < s.size(); i++){
            count = (count + v[i]) % 26;
            s[i] = (char)('a' + (s[i] - 'a' + count + 26)%26);
        }
        return s;
    }
};