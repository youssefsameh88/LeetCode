#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        if(p.size() > s.size()) return {};
        unordered_map<char,int> pLetters;
        unordered_map<char,int> window;
        vector<int> v;
        for(char c : p)  pLetters[c]++;
        int l = 0;
        for(int r = 0; r < s.size(); r++){

            window[s[r]]++;
            if(r-l+1 == p.size()){
                bool ok = true;
                for(auto& [a,b] : pLetters){
                    if(!window.count(a) || window[a] != b) {
                        ok = false;
                        break;
                    }
                }
                if(ok) v.push_back(l);
                
                if(r < s.size()-1){
                    window[s[l]]--;
                    if(window[s[l]] < 1) window.erase(s[l]);
                }
                l++;
            }
        }
        return v;
    }
};

