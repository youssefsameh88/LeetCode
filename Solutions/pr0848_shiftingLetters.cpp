#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) {
        int ps = 0;
        for(int i = s.size() - 1; i >= 0; i--){
            ps = (ps + shifts[i]) % 26;
            s[i] = (char) ('a' + (s[i] - 'a' + ps) % 26);
        }
        return s;

    }
};