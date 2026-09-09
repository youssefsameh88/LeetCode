#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> f;
        for(string word : words) f[word]++;
        vector<string> unique;
        unique.reserve(f.size());
        for(auto& [a,b] : f) unique.push_back(a);

        sort(unique.begin(), unique.end(), [&](string& a, string& b){
            if(f[a] != f[b]) return f[a] > f[b];
            return a < b;
        });
        unique.resize(k);
        return unique;
    }
};