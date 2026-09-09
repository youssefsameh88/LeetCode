#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maximumValue(int n, int s, int m) {
        if(n == 1) return s;
        long long x = s + (long long)((n+!(n%2))/2 * (long long )m) - (n-!(n%2))/2;
        return n%2 ? x + 1 : x;
    }
};