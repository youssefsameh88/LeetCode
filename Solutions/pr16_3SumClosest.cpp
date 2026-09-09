#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int minSum ;
        int minDist = 100000;
        int k;
        for(k = 0 ; k < nums.size() ; k++){

            if (k > 0 && nums[k] == nums[k - 1]) continue;
            
           int l = 0;
           int r = nums.size()-1;
            while(l < r){
                if(l == k) l++;
                if(r == k) r--;
                int sum = nums[l] + nums[r] + nums[k];
                    if(abs(sum-target) < minDist){
                        minSum = sum;
                        minDist = abs(sum - target);
                    }  
                    if(sum < target) l++;
                    else if(sum > target) r--;
                    else return sum;             
            }
            
        }
        
        return minSum;
    }
};

int main(){
    Solution s;

    vector <int> nums = {5,1,-15};
    int v = s.threeSumClosest(nums,10);

    cout<< v;
}