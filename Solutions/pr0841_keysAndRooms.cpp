#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<bool> vis(rooms.size());
        vis[0] = true;
        int totalVis = 1;
        return dfs(rooms,0,totalVis,vis);
    }
    bool dfs(vector<vector<int>>& rooms, int node,int& totalVis, vector<bool>& vis){
        if(totalVis == rooms.size()) return true;
        
        for(int neighbor : rooms[node]){
            if(!vis[neighbor]){
                vis[neighbor] = true;
                totalVis++;
                if(dfs(rooms,neighbor,totalVis,vis)) return true;
            }
        }
        return false;
    }
};