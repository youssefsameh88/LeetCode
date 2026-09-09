#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        vector<int> ps(nums.size() + 1);
        int sum = 0;
        for(int i = 1; i <= nums.size(); i++){
            sum += nums[i-1];
            ps[i] += sum;
        }
        int minLen = INT_MAX;
        for(int i = 0; i < ps.size(); i++){
            if(ps[i] < target) continue;
            int l = 0, r = i, idx = -1;
            while(l <= r){
                int mid = (r + l)/2;
                if(ps[mid] > ps[i] - target){
                    r = mid - 1;
                }
                else{
                    idx = mid;
                    l = mid + 1;
                }
            }
            if(idx != -1)
                 minLen = min(minLen, i - idx);
            
        }
        return minLen == INT_MAX ? 0 : minLen;
    }
};
