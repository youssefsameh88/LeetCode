#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isRobotBounded(string inst) {
        int k = 0, t = 0;
        for(char c : inst) k += c == 'R' ? 1 : c == 'L' ? - 1 : 0;
        if(k%4) return true;
        vector<int> turns(4);
        for(int i = 0; i < inst.size(); i++){
            if(inst[i] == 'R') t++;
            else if (inst[i] == 'L') t--;
            else turns[((t%4)+4)%4]++;
        }
        return turns[0] == turns[2] && turns[1] == turns[3];
    }
};
