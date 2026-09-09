#include<deque>
#include <string>
using namespace std;

class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.size() != goal.size()) return false;
        deque<char> dq1(s.begin(),s.end());
        deque<char> dq2(goal.begin(),goal.end());

        for(int i = 0; i < s.size() ; i++){
            if(dq1 == dq2) return true;
            dq1.push_back(dq1.front());
            dq1.pop_front();
        }
        return false;
    }
};