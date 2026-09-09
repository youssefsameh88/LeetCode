#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        unordered_map<int,int> map;
       int count = 0;
       for(int t : time){
        int r = t % 60;
        int need = (60 - r) % 60;

        if(map.count(need)) count += map[need];

        map[r]++;
       }
        return count;
    }
};