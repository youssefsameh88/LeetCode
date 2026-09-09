#include <vector>
using namespace std;

class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> ps(n + 2);
        for(int i = 0 ; i < bookings.size(); i++){
            ps[bookings[i][0]] +=  bookings[i][2];
            ps[bookings[i][1]+1] -=  bookings[i][2];
        }
        vector<int> v(n);
        int count = 0;
        for(int i = 1; i <= n; i++){
            count += ps[i];
            v[i-1] = count;
        }
        return v;
    }
};