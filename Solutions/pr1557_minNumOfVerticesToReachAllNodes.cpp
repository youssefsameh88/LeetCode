#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<bool> in(n);
        for(int i = 0; i < edges.size(); i++){
            in[edges[i][1]] = true;
        }
        vector<int> v;
        for(int i = 0; i < n; i++){
            if(!in[i])
                v.push_back(i);
        }
        return v;
    }
};