#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        map<char, char> m = {{'(', ')'}, {'{','}'}, {'[',']'} };
        stack<char> st;
        for(int i = 0; i < s.size(); i++){
            if(m.count(s[i])) st.push(s[i]);
            else{
                if(!st.empty() && m[st.top()] == s[i]) st.pop();
                else return false;
            }
        }
        return st.empty();
    }
};
        