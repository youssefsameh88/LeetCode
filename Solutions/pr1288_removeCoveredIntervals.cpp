#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        unordered_map<int,vector<int>> map;
        int idx = 0;
        for(auto& v : intervals) map[idx++] = v;

        int n = intervals.size(), count = 0;
        for(int i = 0; i < n ; i++){
            for(int j = 0; j < n; j++){
                if(i == j || !map.count(i) || !map.count(j)) continue;
                if(map[j][0] <= map[i][0] && map[i][1] <= map[j][1]){
                    count++;
                    map.erase(i);
                }
            }
        }
        return n-count;
    }
};
