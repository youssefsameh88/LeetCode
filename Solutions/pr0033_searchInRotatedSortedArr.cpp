#include <vector>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int s = nums.size(); 
        int l = 0, r = s - 1, m = 0;
        while(l < r){
             m = l + (r-l)/2;
            if(nums[m] > nums[r]) l = m + 1;
            else r = m;
        }
        if(nums[l] == target) return l;
        int i, j;
        if(target >= nums[l] && target <= nums.back()){
            i = l, j = s - 1;
        }        
        else if(target <= nums[(l-1+s)%s] && target >= nums.front()){
            i = 0, j = (l-1+s)%s;
        }
        else return -1;
        while(i <= j){
            m = i + (j-i)/2;
            if(nums[m] < target) i = m + 1;
            else if (nums[m] > target) j = m - 1;
            else return m;
        }
        return -1;
    }
};