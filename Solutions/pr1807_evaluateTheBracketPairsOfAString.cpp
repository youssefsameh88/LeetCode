#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string, string> mp;
        for(auto& v : knowledge) mp[v[0]] = v[1];

        string ans;
        for(int i = 0; i < s.size(); i++){
            if(s[i] != '(') ans += s[i];
            else{
                i++;
                string temp;
                while(s[i] != ')') temp += s[i++];
                ans += mp.count(temp) ? mp[temp] : "?";
            }
        }
        return ans;
    }
};
