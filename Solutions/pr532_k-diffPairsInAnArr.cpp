#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        if(n == 1) return 0;
        int l = n-2 , r = n - 1;

        set <vector<int>> mySet;
        while(r > 0){
            int diff = abs(nums[r] - nums[l]);
            if(diff < k)l--;
            else if(diff > k) {
                r--;
                l = r-1;
            }
            else{
                vector v = {nums[l],nums[r]};
                sort(v.begin() , v.end());
                mySet.insert(v);
                l--;
            }
            if(l < 0){
                r--;
                l = r-1;
            }
        }
        return mySet.size();
    }
};

int main(){
    Solution s;
    vector v = {10,1};
    cout << s.findPairs(v,9);
}