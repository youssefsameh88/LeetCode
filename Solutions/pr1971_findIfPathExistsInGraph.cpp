#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> list(n);
        vector<bool> vis(n);
        for(int i = 0; i < edges.size(); i++){
            list[edges[i][0]].push_back(edges[i][1]);
            list[edges[i][1]].push_back(edges[i][0]);
        }
        return dfs(list,destination,source,vis);
    }
    bool dfs(vector<vector<int>>& list, int dest, int node, vector<bool>& vis){
        if(node == dest) return true;
        for(int neighbor : list[node]){
            if(!vis[neighbor]){
                vis[neighbor] = true;
                if(dfs(list,dest,neighbor,vis)) return true;
            }
        }
        return false;
    }
};