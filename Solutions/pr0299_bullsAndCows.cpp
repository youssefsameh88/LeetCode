#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string getHint(string secret, string guess) {
        int bulls = 0, cows = 0;
        vector<int> v1(10), v2(10);
        for(int i = 0; i < guess.size(); i++){
            if(secret[i] == guess[i]){
                bulls++;
                continue;
            }
            v1[secret[i]-'0']++;
            v2[guess[i]-'0']++;
        }
        for(int i = 0; i < 10; i++){
            cows += min(v1[i],v2[i]);
        }
        return to_string(bulls) + "A" + to_string(cows) + "B";
    }
};
