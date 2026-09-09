#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>
using namespace std;

class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> freq;
        vector<char> v;
        for(int i = 0; i < s.size(); i++)
            freq[s[i]]++;
        for(auto& [a,b] : freq) v.push_back(a);

        sort(v.begin(),v.end(),[&](char a, char b){return freq[a] > freq[b];});
        string ans = "";
        for(int i = 0; i < v.size(); i++)
           ans.append(freq[v[i]],v[i]);
        
        return ans;
    }
};
