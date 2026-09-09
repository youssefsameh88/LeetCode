#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        if(!n || target < nums[0] || target > nums[n-1]) return {-1,-1};

        if(n == 1){
            if(target == nums[0]) return {0,0};
            else return {-1,-1};
        }
        int high = n - 1, low = 0, mid;
        while(low <= high){
             mid = (low + high)/2;
            if(nums[mid] > target) high = mid - 1;
            else if(nums[mid] < target) low = mid + 1;
            else break;
        }
        if(nums[mid] != target) return {-1,-1};
        low = high = mid;
        while(low > 0 && nums[low] == nums[mid]) low--;
        while(high < n && nums[high] == nums[mid]) high++;

        if(!low && nums[low] == target) return {low , high - 1};
        return {low + 1, high - 1};
    }
};