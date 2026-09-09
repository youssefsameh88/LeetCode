#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        string push = "Push", pop = "Pop";
        vector<string> v;
        int i = 0;
        for(int j = 1; j <= n; j++){
            if(i >= target.size()) break;
            if(j == target[i]){
                v.push_back(push);
                i++;
            }
            else{
                v.push_back(push);
                v.push_back(pop);
            }
        }
        return v;
    }
};