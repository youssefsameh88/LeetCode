#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> v(26);
        for(char c : s) v[c-'a']++;
        for(int i = 0; i < s.size(); i++) if(v[s[i]-'a'] == 1) return i;
        return -1;
    }
};