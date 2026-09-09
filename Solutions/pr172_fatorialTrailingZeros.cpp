#include <iostream>
using namespace std;

class Solution {
public:
    int trailingZeroes(int n) {
        if(n < 5) return 0;
        int f = 5 ;
        int sum = 0;
        
        while(n/f > 0){
            sum += n/f;
            f *= 5;
        }
        return sum;
    }
};

int main(){
    Solution s;
    cout << s.trailingZeroes(3120);

}