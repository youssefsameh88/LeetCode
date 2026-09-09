#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    char findKthBit(int n, int k) {
        string s = "0";
        n--;
        while(n--) s += '1' + revInv(s);
        return s[k-1];
    }
    string revInv(string s){
        int n = s.size();
        for(int i = 0; i <= n/2; i++){
            swap(s[i], s[n-i-1]);
            s[i] = s[i] == '0' ? '1' : '0';
            if(i < n/2)s[n-i-1] = s[n-i-1] == '0' ? '1' : '0';
        }
        return s;
    }
};