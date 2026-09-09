#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> ans;
    vector<int> restoreArray(vector<vector<int>>& adj) {
        unordered_map<int,int> map;
        unordered_map<int,vector<int>> adjList;
        for(auto& v : adj){
            map[v[0]]++;
            map[v[1]]++;
            adjList[v[0]].push_back(v[1]);
            adjList[v[1]].push_back(v[0]);
        }
        int start = 0;
        for(auto& [a,b] : map){
            if(b == 1){
                start = a;
                break;
            }
        }
        unordered_set<int> vis;
        dfs(adjList, start, vis);
        return ans;
    }
    void dfs(unordered_map<int,vector<int>>& adj, int node, unordered_set<int>& vis){
        if(vis.count(node)) return;
        ans.push_back(node);
        vis.insert(node);
        dfs(adj,adj[node][0],vis);
        if(adj[node].size() > 1) dfs(adj,adj[node][1],vis);
    }
};
