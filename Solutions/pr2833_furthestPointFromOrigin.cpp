#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int _ = 0, x = 0;
        for(int i = 0; i < moves.size(); i++){
            if(moves[i] == '_') _++;
            else if (moves[i] == 'R') x++;
            else x--;
        }
        return abs(x) + _;
    }
};