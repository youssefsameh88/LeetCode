#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> ans;
    int N;
    vector<string> validStrings(int n) {
        string s = "";
        N = n;
        helper(s);
        return ans;
    }
    void helper(string& s){
        if(s.size() == N){
            ans.push_back(s);
            return;
        }
        if(s.empty() || s.back() == '1'){
            s += '0';
            helper(s);
            s.pop_back();
        }
        s +='1';
        helper(s);
        s.pop_back();
    }
};