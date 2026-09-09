#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int count = 0;
    int findCircleNum(vector<vector<int>>& isConnected) {
        vector<vector<int>> list(isConnected.size());
        for(int i = 0; i < isConnected.size(); i++){
            for(int j = 0; j < isConnected.size(); j++){
                if(i == j) continue;
                if(isConnected[i][j]){
                    list[i].push_back(j);
                    list[j].push_back(i);
                }
            }
        }
        vector<bool>vis(isConnected.size());
        vis[0] = true;
        for(int i = 0; i < list.size(); i++){
            if(!vis[i] || !i){
                dfs(list,vis,i);
                count++;
            }
        }
        return count;
    }
    void dfs(vector<vector<int>>& list,vector<bool>& vis, int node){
        for(int neighbor : list[node]){
            if(!vis[neighbor]){
                vis[neighbor] = true;
                dfs(list,vis,neighbor);
            }
        }
    }
};