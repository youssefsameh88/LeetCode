#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canTransform(vector<int>& source, vector<int>& target) {
        long long a = 0, b = 0;
        for(int num : source) a += num;
        for(int num : target) b += num;
        return a==b;
    }
};