#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumDetonation(vector<vector<int>>& bombs) {
        vector<vector<int>> adj(bombs.size());
        for(int i = 0; i < bombs.size(); i++){
            for(int j = 0; j < bombs.size(); j++){
                if(i == j) continue;
                if(p2Inp1(bombs[i], bombs[j])) adj[i].push_back(j);
            }
        }
        int maxCount = 0;
        for(int i = 0; i < bombs.size(); i++){
            vector<bool> vis(bombs.size());
            int count = 0;
            dfs(adj, i, vis, count);
            maxCount = max(count, maxCount);
        }
        return maxCount;
    }

    bool p2Inp1(vector<int>& p1, vector<int>& p2){
        long long dx = 1LL * p1[0] - p2[0], dy = 1LL * p1[1] - p2[1];
        return dx * dx + dy * dy <= 1LL* p1[2] * p1[2];
    }
    
    void dfs(vector<vector<int>>& adj, int node, vector<bool>& vis, int& count){
        vis[node] = true;
        count++;
        for(int nbor : adj[node]){
            if(!vis[nbor]) 
                dfs(adj, nbor, vis, count);
        }
    }
};
