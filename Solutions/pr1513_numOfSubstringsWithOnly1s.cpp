#include<iostream>
using namespace std;
class Solution {
public:
    int numSub(string s) {
        long long sum = 0;
        int lim = 1e9 + 7;
        for(int i = 0; i < s.size(); i++){
            int c = 0;
            while( i < s.size() && s[i] == '1') c++,i++;
            sum += (long long) c*(c+1)/2;
        }
        return sum%lim;
    }
};
