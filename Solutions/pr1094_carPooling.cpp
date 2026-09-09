#include <vector>
using namespace std;
class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        int maxDest = 0;
        for(vector<int> vec : trips) if(vec[2] > maxDest) maxDest = vec[2];

        vector<int> ps(maxDest + 2);
        for(int i = 0; i < trips.size(); i++){
            ps[trips[i][1]] += trips[i][0];
            ps[trips[i][2]] -= trips[i][0];
        }
        int count = 0;
        for(int i = 0; i <= maxDest; i++){
            count += ps[i];
            if(count > capacity) return false;
        }
        return true;
    }
};