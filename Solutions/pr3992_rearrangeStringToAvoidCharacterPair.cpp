#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string rearrangeString(string s, char x, char y) {
        unordered_map<char, int> map;
        for(char c : s){
            map[c]++;
        }
        string str = "";
        str.append(map[y],y);
        str.append(map[x],x);
        map.erase(x);
        map.erase(y);
        for(auto& [a,b] : map){
            str.append(b,a);
        }
        return str;
    }
};