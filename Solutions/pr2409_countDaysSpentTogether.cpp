#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countDaysTogether(string aa, string la, string ab, string lb) {
        vector<int> days = {0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334};
        int a1 = days[stoi(aa.substr(0,2))-1] + stoi(aa.substr(3,2));
        int a2 = days[stoi(la.substr(0,2))-1] + stoi(la.substr(3,2));
        int b1 = days[stoi(ab.substr(0,2))-1] + stoi(ab.substr(3,2));
        int b2 = days[stoi(lb.substr(0,2))-1] + stoi(lb.substr(3,2));

        if(b1 < a1){
            swap(a1,b1), swap(a2,b2);
        }
        return b1 > a2 ? 0 : min(a2,b2) - b1 + 1;
    }
};
