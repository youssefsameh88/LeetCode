#include <unordered_set>
using namespace std;
class Solution {
public:
        //I thought max right was 10^5 at first
    int countPrimeSetBits(int left, int right) {
        unordered_set<int> set = {2, 3, 5, 7, 11,13,17,19}; 
        int count = 0;
        for(int i = left; i <= right; i++){
            int setBits = 0, x = i;
            while(x > 0){
                if(x & 1 == 1) setBits++;
                x >>= 1; 
            }
             if(set.find(setBits) != set.end()) count++;
        }
        return count;
    }
};