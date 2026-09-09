#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int connected = 0;
    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<vector<int>> list(n);
        for(int i = 0; i < edges.size(); i++){
            list[edges[i][0]].push_back(edges[i][1]);
            list[edges[i][1]].push_back(edges[i][0]);
        }
        long long ans = 0;
        vector<bool> vis(n);
        for(int i = 0; i < n; i++){
            connected = 0;
            if(!vis[i])
                dfs(list, i, vis);
            ans += 1LL * connected * (n - connected);
        }
        return ans/2;
    }
    void dfs(vector<vector<int>>& list, int node, vector<bool>& vis){
        vis[node] = true;
        connected++;
        for(int nbr : list[node]){
            if(!vis[nbr]){
                dfs(list,nbr,vis);
            }
        }
    }
};