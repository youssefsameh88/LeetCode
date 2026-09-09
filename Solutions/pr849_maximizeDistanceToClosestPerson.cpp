#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int Max = 1;
        int steps = 0;
        bool firstIsZero = !seats[0];
        for(int i = 0 ; i < seats.size() ; i++){
            if(firstIsZero){
                while(!seats[i]){
                    i++;
                    steps++;
                }
                Max = max(Max , steps);
                firstIsZero = false;
            }
            if(seats[i]){
                Max = max(Max , steps/2);
                steps = 0;
            }
            if(i == seats.size()-1 && !seats[i]) Max = max(Max , steps);
            steps++;
        }

        return Max;
    }
};

int main(){
    Solution s;

    vector v = {1,0,0};
    cout << s.maxDistToClosest(v);
}