#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int steps = 0 , n = nums.size();
        if(n == 1) return true;
        if(!nums[0]) return false;

        for(int i = 0 ; i < n ; i++){
            while(i < n-1 && nums[i]){
                steps = max(steps, nums[i]);  
                if(nums[i] >= n-i-1) return true;
                i++;
                steps--;                        
            }

            if(i >= n-1) return true;     

            if(i == n-2 && nums[i]) return true;

            while(i < n && !nums[i]){        
                steps--;                      
                if(steps < 0) return false; 
                i++;
            }

            i--;
            
        }
        return true;
    }
};

int main(){
    Solution s;
    vector v = {8,2,4,4,4,9,5,2,5,8,8,0,8,6,9,1,1,6,3,5,1,2,6,6,0,4,8,6,0,3,2,8,7,6,5,1,7,0,3,4,8,3,5,9,0,4,0,1,0,5,9,2,0,7,0,2,1,0,8,2,5,1,2,3,9,7,4,7,0,0,1,8,5,6,7,5,1,9,9,3,5,0,7,5};
    cout << s.canJump(v);
}