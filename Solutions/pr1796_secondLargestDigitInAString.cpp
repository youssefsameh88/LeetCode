#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int secondHighest(string s) {
        set<char> set;
        for(char c : s){
            if(isdigit(c)) set.insert(c);
        }
        if(set.size() < 2) return -1;
        return *(++set.rbegin()) -'0';
    }
};