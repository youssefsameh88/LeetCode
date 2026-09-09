#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findLucky(vector<int>& arr) {
        map<int, int> map;
        for(int num : arr) map[-num]++;
        for(auto& [a,b]:map){
            if(-a == b) return -a; 
        }
        return -1;
    }
};