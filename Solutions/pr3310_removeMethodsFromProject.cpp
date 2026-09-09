#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& inv) {
        unordered_set<int> set, sus;
        sus.insert(k);
        for(int i = 0; i < n; i++) set.insert(i);

        vector<vector<int>> adj(n);
        vector<bool> vis(n); 
        for(int i = 0; i < inv.size(); i++){
            adj[inv[i][0]].push_back(inv[i][1]);
        }
        dfs(adj,vis,k,sus);
        vector<int> ans;
        for(int i = 0; i < inv.size(); i++){
            if(sus.count(inv[i][1]) && !sus.count(inv[i][0])){
                for(int num : set) ans.push_back(num);
                return ans;
            }
        }
        for(int num : set) if(!sus.count(num)) ans.push_back(num);
        return ans;
    }
    void dfs(vector<vector<int>>& adj, vector<bool>& vis, int node, unordered_set<int>& sus){
        if(vis[node]) return;
        vis[node] = true;
        for(int nbor : adj[node]){
            if(vis[nbor]) continue;
            sus.insert(nbor);
            dfs(adj,vis,nbor,sus);
        }
    }
};
