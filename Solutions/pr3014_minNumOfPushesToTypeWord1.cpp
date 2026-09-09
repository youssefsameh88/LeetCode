#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumPushes(string word) {
        int s = word.size(), ans = 0, add = 1;
        while(s > 7){
            ans += 8*add;
            add++;
            s -= 8;
        }
        ans += s * add;
        return ans;
    }
};