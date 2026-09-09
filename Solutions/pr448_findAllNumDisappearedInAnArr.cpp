#include <vector>
using namespace std;
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector <int>v(nums.size(),0);
        for(int num : nums) v[num-1]++;
        
        vector<int> ans;
        for(int i = 0; i < v.size() ; i++)
             if(!v[i]) ans.push_back(i+1);

        return ans;
    }
};