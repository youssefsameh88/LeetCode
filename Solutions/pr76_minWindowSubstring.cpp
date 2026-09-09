#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        if(t.size() > s.size()) return "";
        unordered_map<char, int> map, need;
        for(char c : t) need[c]++;

        unordered_set<char> tLetters(t.begin(), t.end()) ,vis;
        int l = 0, r = 0;
        int bestL = 0, bestR = INT_MAX;
        while(r < s.size()){
            if(tLetters.count(s[r])) {
                map[s[r]]++;
                if(map[s[r]] >= need[s[r]]) vis.insert(s[r]);
            }
        
            while(l <= r && vis.size() == tLetters.size()){
                if(r-l < bestR-bestL){
                    bestR = r, bestL = l;
                }
                if(tLetters.count(s[l])){
                    map[s[l]]--;
                    if(map[s[l]] < need[s[l]]) vis.erase(s[l]);
                    if(!map[s[l]]) map.erase(s[l]);
                }
                l++;
            }

            r++;
        }
        if(bestR == INT_MAX) return "";
        return s.substr(bestL, bestR - bestL + 1);
    }
};