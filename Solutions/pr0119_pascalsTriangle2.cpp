#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> ans(rowIndex+1,1);
        for(int k = 0; k < rowIndex; k++)
            for(int i = k; i > 0; i--)
                ans[i] += ans[i-1];
        return ans;
    }
};
