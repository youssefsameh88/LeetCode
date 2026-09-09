#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    string makeFancyString(string s) {
        if(s.size() < 3) return s;
        string ans = "";
        ans.push_back(s[0]);
        ans.push_back(s[1]);
        int n = 1;
        for(int i = 2 ; i < s.size() ; i++){
            if(s[i] != ans[n] || s[i] != ans[n-1]){
                ans.push_back(s[i]);
                n++;
            }
        }
        return ans;
        
    }
};