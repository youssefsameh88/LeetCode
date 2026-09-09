#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> ans;
    vector<string> letterCasePermutation(string s) {
        for(char& ch : s) ch = tolower(ch);
        helper(0,s);
        return ans;
    }
    void helper(int i, string& s){
        while(i < s.size() && !isalpha(s[i])) i++;
        if(i == s.size()){
            ans.push_back(s);
            return;
        }
        s[i] = toupper(s[i]);
        helper(i+1,s);
        s[i] = tolower(s[i]);
        helper(i+1,s);
    }
};
