#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        multiset<double> ms(nums.begin(),nums.begin()+k);
        auto mid = next(ms.begin(),k/2);
        vector<double> ans;
        int l = 0, r = k;
        while(r < nums.size()){
            if(k%2) ans.push_back(*mid);
            else ans.push_back((*mid + *prev(mid))/2);
            ms.insert(nums[r++]);

            if (nums[r-1] < *mid) mid--;
            if (nums[l] <= *mid) mid++;
            
            ms.erase(ms.find(nums[l++]));
        }

        if(k%2) ans.push_back(*mid);
        else ans.push_back((*mid + *prev(mid))/2);

        return ans;
    }
};