#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string maxValue(string n, int x) {
        int i = 0;
        if(n[0] == '-'){
            i++;
            while(i < n.size() && n[i]-'0' <= x) i++;
            string s = to_string(x);
            n.insert(i,s);
            return n;
        }
        while(i < n.size() && n[i]-'0' >= x) i++;
        string s = to_string(x);
            n.insert(i,s);
        return n;
    }
};