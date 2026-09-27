#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        vector<int> freq(10);
        int ans = 0;
        for(int d : digits) freq[d]++;

        for(int i = 1; i < 10; i++){
            if(!freq[i]) continue;
            freq[i]--;
            for(int j = 0; j < 10; j++){
                if(!freq[j]) continue;
                freq[j]--;
                for(int k = 0; k < 9; k += 2){
                    if(freq[k]) ans++;
                }
                freq[j]++;
            }
            freq[i]++;
        }
        return ans;
    }
};
