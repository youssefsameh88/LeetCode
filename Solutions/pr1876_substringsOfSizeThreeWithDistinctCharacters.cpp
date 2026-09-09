#include<iostream>
using namespace std;

class Solution {
public:
    int countGoodSubstrings(string s) {
        int ans = 0;
        if(s.size() < 3) return 0;
        for(int i = 0; i < s.size()-2;i++){
            char x = s[i];
            char y = s[i+1];
            char z = s[i+2];
            if(x==y || y==z || z==x) continue;
            ans++;
        }
        return ans;
    }
};