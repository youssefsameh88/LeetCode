#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string sortVowels(string s) {
        vector<pair<int,int>> frq(26,{0,1e7});
        vector<int> idx;
        vector<char> allVowels;
        set<char> vowels= {'a', 'e', 'i', 'o', 'u'};

        for(int i = 0; i < s.size(); i++){
            if(vowels.count(s[i])){
                allVowels.push_back(s[i]);
                idx.push_back(i);
                frq[s[i]-'a'].first++;
                if(i < frq[s[i]-'a'].second)
                    frq[s[i]-'a'].second = i;
            }
        }
        sort(allVowels.begin(), allVowels.end(), [&](char& a, char& b){
            if(frq[a-'a'].first != frq[b -'a'].first)
                return frq[a-'a'].first > frq[b -'a'].first;
            return frq[a-'a'].second < frq[b -'a'].second;
        });
        for(int i = 0; i < idx.size(); i++){
            s[idx[i]] = allVowels[i];
        }
        return s;
    }
};
