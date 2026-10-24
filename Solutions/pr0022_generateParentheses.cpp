#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> ans;
    vector<string> generateParenthesis(int n) {
        string s = "";
        helper(s,n,0);
        return ans;
    }
    void helper(string& s, int n, int m){
        if(s.size() == 2*n){
            if(m == 0) ans.push_back(s);
            return;
        }
        if(m < 0) return;
        s += '(';
        helper(s,n,m+1);
        if(!s.empty())s.pop_back();
        s += ')';
        helper(s,n,m-1);
        s.pop_back();
    }
};
