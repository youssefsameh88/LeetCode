#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> ans;
    vector<string> letterCombinations(string digits) {
        unordered_map<char, string> map;
        string s = "";
        map['2'] = "abc";
        map['3'] = "def";
        map['4'] = "ghi";
        map['5'] = "jkl";
        map['6'] = "mno";
        map['7'] = "pqrs";
        map['8'] = "tuv";
        map['9'] = "wxyz";
        helper(map,s,digits,0);
        return ans;
    }
    void helper(unordered_map<char, string>& map, string& s,string& digits, int i){
        if(s.size() == digits.size()){
            ans.push_back(s);
            return;
        }
        string temp = map[digits[i]];
        for(int k = 0; k < temp.size(); k++){
            s += temp[k];
            helper(map,s,digits,i+1);
            s.pop_back();
        }
        
    }
};