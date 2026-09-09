#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string smallestPalindrome(string s) {
        vector<int> freq(26);
        for(int i = 0; i < s.size(); i++) freq[s[i]-'a']++;
        
        string ans1 = "";
        for(int i = 0; i < 26; i++)
            ans1.append(freq[i]/2, i+'a');
        
        string ans2 = ans1;
        int i = 0;
        while(i < 26) if(freq[i++]%2) break;
        if(freq[--i]%2) ans1 +=(i+'a');
        reverse(ans2.begin(),ans2.end());
        ans1 += ans2;
        return ans1;
    }
};
