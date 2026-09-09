#include <vector>
using namespace std;
class Solution {
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int lim = 1e9 + 7;
        for(int i = 0 ; i < queries.size(); i++){
            int idx = queries[i][0];
            while(idx <= queries[i][1]){
                 nums[idx] = (int)(((long) nums[idx]*queries[i][3]) % lim);
                idx += queries[i][2];
            }
        }
        int n = 0;
        for(int num : nums) n^= num;
        return n;
    }
};