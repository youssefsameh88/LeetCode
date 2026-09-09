#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int closestTarget(vector<string>& words, string target, int si) {
        int mn = INT_MAX;
        for(int i = 0; i < words.size(); i++){
            if(words[i] == target){
                mn = min(mn, min(abs(si-i), abs((int)words.size()-abs(si-i))));
            }
        }
        return mn == INT_MAX ? -1 : mn;
    }
};
