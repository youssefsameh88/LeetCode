#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int count = 0;
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<pair<int,int>>> adj(n);
        vector<bool> vis(n);
        for(int i = 0; i < connections.size(); i++){
            adj[connections[i][0]].push_back({connections[i][1],1});
            adj[connections[i][1]].push_back({connections[i][0],0});
        }
        dfs(adj,0,vis);
        return count;
    }
    void dfs(vector<vector<pair<int,int>>>& adj, int node, vector<bool>& vis){
        vis[node] = true;
        for(auto [nbr,dir] : adj[node]){
            if(!vis[nbr]){
                if(dir == 1)
                    count++;
                dfs(adj,nbr,vis);
            }
        }
    }
};