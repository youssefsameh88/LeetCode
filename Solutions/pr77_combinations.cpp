#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> ans;
    int N, K;
    vector<vector<int>> combine(int n, int k) {
        N = n, K = k;
        vector<int> v;
        helper(v,1);
        return ans;
    }
    void helper(vector<int>& v, int start){
        if(v.size() == K){
            ans.push_back(v);
            return;
        }
        for(int i = start; i <= N; i++){
                v.push_back(i);
                helper(v,i+1);
                v.pop_back();
            }
        }
};
