#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numberOfSubstrings(string s) {
        int l = 0, r = 0, ans = 0, n = s.size();
        vector<int> frq(3);
        while(r < n){
            frq[s[r]-'a']++;
            while(frq[0] && frq[1] && frq[2]){
                ans += n - r;
                frq[s[l]-'a']--;
                l++;
            }
            r++;
        }
        return ans;
    }
};