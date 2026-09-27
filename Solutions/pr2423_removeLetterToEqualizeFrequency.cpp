#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool equalFrequency(string word) {
        map<char,int> mp;
        map<int,int> frq;

        for(char c : word) mp[c]++;
        for(auto& [a,b] : mp) frq[b]++;

        if(frq.size() > 2) return false;

        if(frq.size() == 1 && (mp.begin()->second == 1 || frq.begin()->second ==1)) return true;
        if(frq.size() == 2 && frq.begin()->first == 1 && frq.begin()->second == 1) return true;

        if(frq.size() == 2 && frq.rbegin()->first - 1 == frq.begin()->first &&
           frq.rbegin()->second == 1)
            return true;

        return false;
    }
};