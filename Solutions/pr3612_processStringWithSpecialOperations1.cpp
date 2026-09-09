#include <string>
using namespace std;
class Solution {
public:
    string processStr(string s) {
        string ans = "";
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '*'){
                if(!ans.empty()) ans.pop_back();
            }
            else if(s[i] == '#') ans += ans;
            else if(s[i] == '%') reverse(ans);
            else ans.push_back(s[i]);
        }
        return ans;
    }
    string reverse(string& s){
        int l = 0, r = s.size() - 1;
        while(l < r) swap(s[l++],s[r--]);
        return s;
    }
};
