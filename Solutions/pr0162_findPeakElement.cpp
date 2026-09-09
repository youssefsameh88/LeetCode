#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if(nums.size() == 1) return 0;
        if(nums.size() == 2) return nums[0] > nums[1] ? 0 : 1;   
        int l = 0 , r = nums.size() - 1;
        int last = nums.size() - 1;
        while( l <= r){
            int m = (l + r)/2;
            if(m == 0){
                if(nums[m] > nums[m+1]) return m;
                else l = m + 1;
            }
            else if(m == last){
                if(nums[m] > nums[m-1]) return m;
                else r = m - 1;
            }
            else{
                if(nums[m-1] > nums[m]) r = m - 1;
                else if(nums[m+1] > nums[m]) l = m+1;
                else return m;
            }
        }
        return -1;
    }
};

int main(){
    Solution s;
    vector v = {1};
    cout << s.findPeakElement(v);

}