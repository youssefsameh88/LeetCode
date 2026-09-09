#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& gs) {
        vector<vector<int>> ans;
        map<int,int> frq;
        for(int i = 0; i < gs.size(); i++){
            frq[gs[i]]++;
        }
        for(auto& [a,b] : frq){
            for(int i = 0; i < b/a; i++)
                ans.push_back(vector<int>(a, -1));
        }
        for(int i = 0; i < gs.size(); i++){
            int j = 0;
            while(ans[j].size() != gs[i] || (ans[j].size() == gs[i] ) && (ans[j].back() != -1)) j++;

            int k = 0;
            while(ans[j][k] != -1) k++;
            ans[j][k] = i;
        }
        return ans;
    }
};