#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int hIndex(vector<int>& c) {
        sort(c.begin(),c.end(), greater<int>());
        int h = 0;
        for(int i = 0; i < c.size(); i++)
            if(c[i] >= i+1) h = i+1;
        
        return h;
    }
};