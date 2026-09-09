#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canReach(vector<int>& start, vector<int>& target) {
        return !((start[0]&1) == (start[1]&1)) ^ ((target[0]&1) == (target[1]&1));
    }
};