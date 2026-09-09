#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int l = matrix[0][0], r = matrix.back().back();
        while(l < r){
            int mid = l + (r-l)/2;
            int x = sum(matrix,mid);
            if(x < k) l = mid+1;
            else r = mid;
        }
        return l;
    }
    int sum(vector<vector<int>>& m, int num){
        int count = 0;
        for(int i = 0; i < m.size(); i++){
            count += upper_bound(m[i].begin(),m[i].end(),num) - m[i].begin();
        }
        return count;
    }
};