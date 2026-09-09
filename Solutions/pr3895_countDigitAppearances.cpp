#include <vector>
using namespace std;
class Solution {
public:
    int countDigitOccurrences(vector<int>& nums, int digit) {
        int count = 0;
        for(int i = 0; i < nums.size() ; i++){
            while(nums[i]){
                if(nums[i]%10 == digit) count++;
                nums[i] /= 10;
            }
        }
        return count;
    }
};