#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool squareIsWhite(string c) {
        return c[0]%2 ^ c[1]%2; 
    }
};