#include <set>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    if(k == 1) return nums;
        multiset<int> ms(nums.begin(),nums.begin()+k);
        vector<int> ans(1,*ms.rbegin());
        int l = 0, r = k;
        while(r < nums.size()){
            ms.insert(nums[r++]);
            ms.erase(ms.find(nums[l++]));
            ans.push_back(*ms.rbegin());
        }
        return ans;
    }
};