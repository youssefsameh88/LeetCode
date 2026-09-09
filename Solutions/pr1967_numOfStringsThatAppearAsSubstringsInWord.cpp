#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int count = 0;
        for(string s : patterns) count += word.find(s) != string::npos ;
        return count;
    }
};