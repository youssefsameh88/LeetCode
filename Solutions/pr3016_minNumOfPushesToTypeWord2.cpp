#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumPushes(string word) {
       vector<int> v(26);
    int x = 8, ans = 0;
       for(char c : word) v[c- 'a']++;
       sort(v.begin(),v.end());
       for(int i = 25; i>= 0; i--){
        if(!v[i]) continue;
        ans += x/8 * v[i];
        x++;
    }
    return ans;
    }
};