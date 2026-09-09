#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;
        if(k == 0 || n == 1 || k == n) return nums;
      vector <int> ans;
        ans.push_back(nums[n-k]);
       for(int i = (n - k+1)%n ; i != (n-k)%n ;i++){
            i = i%n;
           ans.push_back(nums[i]);
       }

       nums = ans;
       return nums;
    }
     
};

int main(){
    Solution s;
    vector v = {1,2,3,4,5,6,7};
    int k = 3;
    vector <int> g = s.rotate(v,k);
    for(int i :g ) cout << i<<" ";
}
