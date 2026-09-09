#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> filterRestaurants(vector<vector<int>>& r, int vf, int mp, int md) {
        vector<vector<int>> take;
        for(int i = 0; i < r.size(); i++){
            if((vf == r[i][2] || !vf) && r[i][3] <= mp && r[i][4] <= md)
                take.push_back(r[i]);
        }
        sort(take.begin(),take.end(), [&](vector<int>& a, vector<int>& b){
            if(a[1] != b[1]) return a[1] > b[1];
            return a[0] > b[0];
        });
        vector<int> ans;
        for(int i = 0; i < take.size(); i++){
            ans.push_back(take[i][0]);
        }
        return ans;
    }
};