#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> ans;
    vector<int>* v;
    vector<vector<int>> subsets(vector<int>& nums) {
        v = &nums;
        vector<int> seq;
        helper(0,seq);
        return ans;
    }
    void helper(int i, vector<int>& seq){
        if(i == v->size()){
            ans.push_back(seq);
            return;
        }
        seq.push_back((*v)[i]);
        helper(i+1, seq);
        seq.pop_back();
        helper(i+1, seq);
    }
};
