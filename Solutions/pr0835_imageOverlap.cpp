#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int mx = 0, n = img1.size();
        for(int ki = 0; ki < 2*n; ki++){
            for(int kj = 0; kj < 2*n; kj++){
                int count = 0;
                for(int i = 0; i < n; i++){
                    for(int j = 0; j < n; j++){
                        int i1 = i+ki-(n-1), j1 = j+kj-(n-1);
                        int x = i1 < n && j1 < n && i1 >= 0 && j1 >= 0 && img1[i1][j1] == 1 ? 1 : 0;
                        if(x & img2[i][j]) count++;
                    }
                mx = max(mx,count);
                }
            }
        }
        
        return mx;
    }
};
