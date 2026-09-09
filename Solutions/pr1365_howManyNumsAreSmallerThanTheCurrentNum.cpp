#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector <int> v = nums;
        vector <int> ans;
        sort(v.begin(),v.end());
        for(int num : nums){
            int l = 0, r = nums.size() - 1, mid = 0;
            int count = 0;
            while(l <= r){
                 mid = l + (r-l)/2;
                if(v[mid] < num) l = mid + 1;
               else if(v[mid] > num) r = mid - 1;
               else{
                count = mid;
                r = mid - 1;
               }
            }
             ans.push_back(count);
        }
        return ans;
    }
};