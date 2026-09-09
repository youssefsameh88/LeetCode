#include <iostream>
#include <cmath>
using namespace std;

class Solution {
public:
    int bulbSwitch(int n)  {
        return int(sqrt(n));
    }
};

int main(){
    Solution s;
    cout << s.bulbSwitch(1000000000);
}
