#include <vector>
#include <set>
using namespace std;

class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int n = nums.size();
        multiset<int> ms;
        int i = 0, j = 0, maxSize = 0;
        while(j < n){
                ms.insert(nums[j]);
                while(!ms.empty() && *ms.rbegin() - *ms.begin() > limit){
                    ms.erase(ms.find(nums[i]));
                    i++;
                }
                maxSize = max(maxSize,j-i+1);
                j++;   
        }
        return maxSize;
    }
};