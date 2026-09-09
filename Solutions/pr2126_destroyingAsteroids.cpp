#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        sort(asteroids.begin(),asteroids.end());
        long long sum = mass;
        for(int asteroid : asteroids){
            if(sum >= asteroid) sum+=asteroid;
            else return false;
        }
        return true;
    }
};