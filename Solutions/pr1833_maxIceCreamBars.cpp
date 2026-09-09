#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        map<int,int> map;
        for(int num : costs) map[num]++;
        int iceCreams = 0;
        auto it = map.begin();
        while(it != map.end() && coins >= it->first){
            if(it->second == 0){
                it++; 
                continue;
            }
            int buy = min(it->second, coins/it->first);
            iceCreams += buy;
            coins -= buy * it->first;
            it++;
        }
        return iceCreams;
    }
};
