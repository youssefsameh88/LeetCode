#include <vector>
using namespace std;
class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int alt = 0, maxAlt = 0;
        for(int num : gain){
            alt += num;
            if(alt > maxAlt) maxAlt = alt;
        }
        return maxAlt;
    }
};