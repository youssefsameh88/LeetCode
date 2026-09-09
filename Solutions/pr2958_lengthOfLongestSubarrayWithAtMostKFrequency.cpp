#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map <int, int> freqMap;
        int left = 0, right = 0, Max = 0;
        for(int i = 0; i < nums.size() ; i++){
            freqMap[nums[i]]++;
            right++;
            
               while(freqMap[nums[i]] > k){
                freqMap[nums[left]]--;
                left++;
               }
            Max = max(Max, right - left);
            }
        return Max;
        }
    };