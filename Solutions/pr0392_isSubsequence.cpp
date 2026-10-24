#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isSubsequence(string s, string t) {
        if(s.size() > t.size()) return false;
        int l = 0, r = 0;
        while(l < s.size()){
            while(r < t.size() && s[l] != t[r]) r++;
            if(r >= t.size()) return false;
            r++, l++;
        }
        return true;
    }
};
