#include <vector>
using namespace std;
class Solution {
public:
    int compareBitonicSums(vector<int>& nums) {
        
        long long sumUp = 0, sumDown = 0;
        int i = 0, size = nums.size();
        while(i < size - 1 && nums[i] < nums[i+1]) i++;

        for(int j = 0; j < nums.size() ; j++){
            if(j < i) sumUp += nums[j];
            else if (j > i)sumDown += nums[j];
            else{
                sumUp += nums[j];
                sumDown += nums[j];
            }
        }
        if(sumUp > sumDown) return 0;
        if(sumUp < sumDown) return 1;
         return -1;
    }
};
