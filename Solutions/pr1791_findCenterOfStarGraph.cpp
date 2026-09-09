#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        unordered_map<int,int> map;
        map[edges[0][0]]++, map[edges[0][1]]++;
        map[edges[1][0]]++, map[edges[1][1]]++;
        for(auto [a,b] : map){
            if(b > 1) return a;
        }
        return -1;
    }
};