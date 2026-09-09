#include <vector>
using namespace std;

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int s = nums.size(); 
        int l = 0, r = s - 1, m = 0;
        while(l < r){
            if(nums[l] == nums[l+1]) l++;
            else if(r > 0 && nums[r] == nums[r-1]) r--;
            else break;
        }
        while(l < r){
             m = l + (r-l)/2;
            if(nums[m] > nums[r]) {
                l = m + 1;
                while(l < r && nums[l] == nums[l+1]) l++;
            }
            else if(nums[m] < nums[r]){
                r = m;
                while(l < r && nums[r] == nums[(r-1+s)%s]) r--;
            }
            else r = m - 1;
        }
        if(nums[l] == target) return true;
        int i, j;
        if(target >= nums[l] && target <= nums.back()){
            i = l, j = s - 1;
        }        
        else if(target <= nums[(l-1+s)%s] && target >= nums.front()){
            i = 0, j = (l-1+s)%s;
        }
        while(i <= j){
            m = i + (j-i)/2;
            if(nums[m] < target) {
                i = m + 1;
                while(i < j && nums[i] == nums[i+1]) i++;
            }
            else if (nums[m] > target) {
                j = m - 1;
                while(j > i && nums[j] == nums[(j-1+s)%s]) j--;
                }
            else return true;
        }
        return false;
    }
};