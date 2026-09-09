#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> ans, v;
        for(int k = 1; k < 10; k++){
            for(int i = 1; i < 10-k; i++){
                int sum = i, count = i+1;
                for(int j = 0; j < k; j++){
                    sum = 10*sum + count;
                    count++;
                }
                v.push_back(sum);
            }
        }
        for(int num : v) if(num >= low && num <= high) ans.push_back(num);
        return ans;
    }
    
};