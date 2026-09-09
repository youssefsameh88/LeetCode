#include <vector>
#include <cmath>
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4){
        vector<vector<int>> v = {p1,p2,p3,p4};
        unordered_set <double> set;
        int j = 0;
        while(j < 2){
           int i = 0;
            while(i++ < v.size())
                set.insert(distance(v[i%4],v[(i+j+1)%4]));
            j++;
        }
        if(set.size() != 2 || set.find(0) != set.end()) return false;
        return true; 
    }
    double distance(vector<int>& p1, vector<int>& p2){
        double x = p1[0] - p2[0];
        double y = p1[1] - p2[1];
        return sqrt(x*x + y*y);
    }
};