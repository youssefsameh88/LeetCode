#include <vector>
using namespace std;
class Solution {
public:
    vector<int> countOppositeParity(vector<int>& nums) {
        vector<int> v(nums.size());
        int sumO = 0, sumE = 0;
        for(int i = nums.size()-1; i >= 0 ; i--) {
            if(nums[i]%2) {
                v[i] = sumE;
                sumO++;
                }
            else {
                v[i] = sumO;
                sumE++;
                }
        }
        return v;
    }
};
