#include <vector>
using namespace std;

class Solution {
public:
    vector<int> evenOddBit(int n) {
        int even = 0, odd = 0;
        bool isEven = true;
        while(n > 0){
            if(n%2){
                if(isEven) even++;
                else odd++;
            }
            isEven = !isEven;
            n >>= 1;
        }
        return {even, odd};
    }
};