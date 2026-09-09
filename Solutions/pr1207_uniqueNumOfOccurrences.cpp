#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        map<int,int> m;
        set<int> s;
        for(int num : arr) m[num]++;
        for(auto [a,b] : m){
            if(s.count(b)) return false;
            s.insert(b);
        }
        return true;
    }
};
