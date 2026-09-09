#include <vector>
using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        if(nums[n-1] > nums[0]) return nums[0];
        
        int l = 0, r = n - 1 , mid = 0;
        while(l < r){
             mid = (l+r)/2;
            if(nums[mid] < nums[r]) r = mid;
            else if(nums[r] ==nums[mid]) r--;
            else if(nums[l] == nums[mid]) l++;
            else l = mid+1;
        } 
        return nums[l];
    }
};
