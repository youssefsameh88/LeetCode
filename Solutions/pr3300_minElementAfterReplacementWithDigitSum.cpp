#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int minElement(vector<int>& nums) {
        int m = INT_MAX;
        for(int num : nums){
            int sum = 0;
        while(num > 0){
            sum += num % 10;
            num /= 10;
        }
           m = min(m,sum);
        }
        
        return m;
    }
};
