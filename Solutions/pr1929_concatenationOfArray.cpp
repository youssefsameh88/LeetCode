#include <iostream>
#include <vector>
using namespace std;

class Solution1929
{
public:
    vector<int> getConcatenation(vector<int> &nums)
    {
        vector<int> ans(nums.size() * 2, 0);
        int k = nums.size();
            
            for (int j = 0; j < 2*k ; j++)
                ans[j] = nums[j % k];
        
        return ans;
    }
};

int main(){

    Solution1929 s;
    vector <int> a = {1,3,2,1};
    vector <int> k = s.getConcatenation(a);

    for (size_t i = 0; i < k.size(); i++)
    {
        cout << k[i] << " ";
    }
    
}