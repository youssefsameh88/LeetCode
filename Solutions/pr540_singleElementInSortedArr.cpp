#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        int l = 0, r = n - 1;
        while(l <= r){
            int m = (l + r) / 2;

            if((r - l) > 3){
                if( nums[m] == nums[m-1]) {
                    if(m%2) l = m + 1;
                    else r = m - 2;
                }
                else if( nums[m] == nums[m+1]) {
                    if(m%2) r = m - 1;
                    else l = m + 2;
                }
                else return nums[m];
            }   
            else return (nums[l] ^ nums[m] ^ nums[r]); 
        }
        return -1;
    }  
};

int main(){
Solution s;
vector v = {1};
cout << s.singleNonDuplicate(v);

}