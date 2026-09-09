#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minMirrorPairDistance(vector<int>& nums) {
        unordered_map<int,int> map;
        int mn = INT_MAX;
        for(int i = 0; i < nums.size(); i++){
            if(map.count(nums[i])) mn = min(mn, i - map[nums[i]]);
              
            map[mirror(nums[i])] = i;
        }
        return mn == INT_MAX ? -1 : mn;
    }
    int mirror(int n){
        long long num = 0;
        while(n && n%10 == 0) n /= 10;
        while(n){
            num += n%10;
            num *= 10;
            n /= 10;
        }
        num /= 10;
        return num;
    }
};
