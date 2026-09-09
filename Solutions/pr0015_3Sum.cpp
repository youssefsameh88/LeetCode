#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector <vector<int>> ans;

        sort(nums.begin(),nums.end());

        int tIdx;
        for(tIdx = 0 ; tIdx < nums.size() ; tIdx++){

            if (tIdx > 0 && nums[tIdx] == nums[tIdx - 1]) continue;
            
           int l = tIdx + 1;
           int r = nums.size()-1;
            while(l < r){
                int sum = nums[l] + nums[r] + nums[tIdx];
                if(sum > 0) r--;
                else if(sum < 0) l++;
                else {
                    ans.push_back({nums[tIdx] , nums[l], nums[r]});

                    while (l < r && nums[l] == nums[l + 1]) l++;
                    while (l < r && nums[r] == nums[r - 1]) r--;

                    l++;
                    r--;
                } 
            }
            
        }
        return ans;
    }
};

int main(){
    Solution s;

    vector <int> nums = {7,-10,7,3,14,3,-2,-15,7,-1,-7,6,-5,-1,3,-13,6,-15,-10,14,8,5,-10,-1,1,1,11,6,8,5,-4,0,3,10,-12,-6,-2,-6,-6,-10,8,-5,12,10,1,-8,4,-8,-8,2,-9,-15,14,-11,-1,-8,5,-13,14,-2,0,-13,14,-12,12,-13,-3,-13,-12,-2,-15,4,8,4,-1,-6,11,11,-7,-12,-2,-8,10,-3,-4,-6,4,-14,-12,-5,0,3,-3,-9,-2,-6,-15,2,-11,-11,8,-11,8,-7,8,14,-5,4,10,3,-1,-15,10,-6,-11,13,-5,1,-15};
    vector <vector<int>> v = s.threeSum(nums);

    for(vector<int> m : v){
        for(int i : m){
            cout << i <<" ";
        }
        cout << endl;
    }
}