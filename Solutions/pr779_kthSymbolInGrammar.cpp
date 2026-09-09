#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int kthGrammar(int n, int k) {
        if(n == 1) return 0;
        if(n == 2) return k == 1 ? 0 : 1;
        long x = 1 << (n-2);
        if(k > x) return !kthGrammar(n-1, k - x);
        return kthGrammar(n-1, k);
    }
};
