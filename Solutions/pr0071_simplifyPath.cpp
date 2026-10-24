#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
        int n = path.size();
        vector<string> st;
        for(int i = 0; i < path.size(); i++){
            while(i < n && path[i] == '/') i++;
            int j = i;
            while(j < n && path[j] != '/') j++;
            string t = path.substr(i, j-i);
            if(t == ".." && !st.empty()) st.pop_back();
            else if(t != ".." && t != ".") st.push_back(t);
            i = j-1;
        }
        string ans;
        for(int i = 0; i < st.size(); i++){
            ans +=  "/" + st[i];
        }
        if(!ans.empty() && ans.back() == '/') ans.pop_back();
        return ans == "" ? "/" : ans;
    }
    
};
