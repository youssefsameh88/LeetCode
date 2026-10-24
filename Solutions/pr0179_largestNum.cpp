#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end(), [](int a, int b){
            string x = to_string(a);
            string y = to_string(b);
            return  x+y >  y+x;
        });
        string ans;
        for(int num : nums) ans += to_string(num);
        return ans[0] == '0' ? "0" : ans;
    }
};
