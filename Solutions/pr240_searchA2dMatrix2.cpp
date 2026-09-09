#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        for(vector<int>& v : matrix){
            if(binary_search(v.begin(), v.end(), target)) return true;
        }
        return false;
    }
};