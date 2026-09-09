#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int bitwiseComplement(int n) {
        if(!n) return 1;
        int x = __builtin_clz(n);
        return (~(n << x) >> x);
    }
};
