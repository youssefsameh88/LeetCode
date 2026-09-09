#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxDistance(string s, int k) {
        int ns = 0, ew = 0, ans = 0;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == 'N') ns++;
            else if(s[i] == 'S') ns--;
            else if(s[i] == 'E') ew++;
            else  ew--;
            int dist = abs(ns) + abs(ew);
            ans = max(ans, min(2*k + dist, i + 1));
        }
        return ans;
    }

};