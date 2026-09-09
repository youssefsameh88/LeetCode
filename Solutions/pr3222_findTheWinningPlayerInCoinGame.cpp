#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string winningPlayer(int x, int y) {
        return min(x,y/4) % 2 ? "Alice" : "Bob";
    }
};