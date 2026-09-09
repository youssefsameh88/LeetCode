#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

class Solution {
public:
    vector<double> internalAngles(vector<int>& sides) {
        double pi = 3.1415926535;
        int a = sides[0], b = sides[1], c = sides[2];
        if(a+b <= c || a+c <= b || b+c <= a) return {};
        double a1 = acos((double)(a*a + b*b - c*c)/(2*a*b))*180/pi;
        double a2 = acos((double)(c*c + b*b - a*a)/(2*c*b))*180/pi;
        double a3 = 180 - a1 - a2;
        vector<double> ans = {a1, a2, a3};
        sort(ans.begin(), ans.end());
        return ans;
    }
};
