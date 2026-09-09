#include <iostream>
using namespace std;
class Solution {
public:
    bool validDigit(int n, int x) {
        string s = to_string(n);
        int num = s[0] - '0';
        if(num == x) return false;

        for(int i = 1; i < s.size(); i++){
            if(s[i] - '0' ==  x) return true;
        }
        return false;
    }
};