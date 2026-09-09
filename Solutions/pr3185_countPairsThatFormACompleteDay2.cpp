#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    long long countCompleteDayPairs(vector<int>& hours) {
        unordered_map<int,int> map;
        int i = 1;
        while(i < hours.size()) map[hours[i++]%24]++;
        
        long long count = 0;
        i = 0;
        while(i < hours.size()-1){
            int x = (24 - hours[i]%24)%24;
            if(map.find(x) != map.end()){
                count += map[x];
                }
                map[hours[i+1] % 24]--;
                i++;
        }
        return count;
    }
};
