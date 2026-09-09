#include <iostream>
using namespace std;

class Solution {
public:
    double angleClock(int hour, int minutes) {
        double minAng = 6 * minutes ;
        double hourAng = 30 * hour + 0.5 * minutes;
         
        return min(abs(minAng-hourAng) , 360 - abs(minAng-hourAng));

    }
};