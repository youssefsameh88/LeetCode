#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    char kthCharacter(int k) {
        if(k == 1) return 'a';
        if(k == 2) return 'b';
        return helper(k, ceil(log2(k)));
    }
    char next(char c){
        return (c-'a' + 1)%26 +'a';
    }
    char helper(int k, int n){
        if(n == 0) return 'a';
        int x = 1 << (n-1);
        if(k > x) return next(helper(k-x, n-1));
        return helper(k, n-1);
    }
};