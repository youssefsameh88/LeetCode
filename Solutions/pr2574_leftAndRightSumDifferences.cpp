#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int Rsum = 0, Lsum = 0;
        vector <int> v(nums.size());
        for(int i = 0; i < nums.size(); i++) Rsum += nums[i];
        for(int i = 0; i < nums.size(); i++){
            Rsum -= nums[i];
            v[i] = abs(Rsum - Lsum);
            Lsum += nums[i];
        }
        return v;
    }
};