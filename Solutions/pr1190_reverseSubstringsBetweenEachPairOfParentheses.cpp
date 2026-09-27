#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string reverseParentheses(string s) {
        stack<string> st;
        st.push("");
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '(') st.push("");
            else if(s[i] == ')'){
                string temp = st.top();
                reverse(temp.begin(), temp.end());
                st.pop();
                st.top() += temp;
            }
            else st.top() += s[i];
        }
        return st.top();
    }
};
