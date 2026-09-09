#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for(int i = 0; i < edges.size(); i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        vector<bool> vis(n);
        int count = 0;
        for(int i = 0; i < n; i++){
            if(vis[i]) continue;
            int m = 0, e = 0;
            dfs(adj,i,vis, m, e);
            e /= 2;
            if(e == m*(m-1)/2) count++;
        }
        return count;
    }
    void dfs(vector<vector<int>>& adj, int node, vector<bool>& vis, int& m, int& e){
        vis[node] = true;
        m++;
        e += adj[node].size();
        for(int nbor : adj[node]){
            if(vis[nbor]) continue;
            dfs(adj,nbor, vis, m, e);
        }
    }
};
