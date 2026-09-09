#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minOperations(vector<string>& logs) {
        int steps = 0;
        for(string log : logs){
            if(log == "../") steps = max(0, steps-1);
            else if(log == "./"){}
            else steps++;
        }
        return steps;
    }
};
