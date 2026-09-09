#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<bool> vis(graph.size());
        vector<int> v;
        v.push_back(0);
        dfs(graph,vis,0,v);
        return ans;
    }
    void dfs(vector<vector<int>>& graph, vector<bool>& vis, int node, vector<int>& path){
        if(node == graph.size() - 1){
            ans.push_back(path);
            return;
        }
        if(vis[node]) return;
        vis[node] = true;
        for(int nbor : graph[node]){
            if(!vis[nbor]){
                path.push_back(nbor);
                dfs(graph,vis,nbor,path);
                path.pop_back();
            }
        }
        vis[node] = false;
    }
};
