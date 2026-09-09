#include <vector>
#include <unordered_set>
using namespace std;
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        if(nums.size() == 1) return false;
        unordered_set <int> set;
        k = min(k, (int)nums.size() - 1);
        for(int i = 0 ; i < nums.size() ; i++){
            if( i > k) set.erase(nums[i-k-1]);
            if(set.find(nums[i]) == set.end()) set.insert(nums[i]);
            else return true;
        }
        return false;
    }
};