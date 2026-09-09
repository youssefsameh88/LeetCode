#include <iostream>
#include <vector>
using namespace std;

class Solution1470 {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector <int> ans(2*n,0);
        for(int i = 0 ; i < n ; i++){
            ans[2 * i] = nums[i];
            ans[2* i +1] = nums[i+n];
        }
        return ans;
    }
};

int main(){
    
    Solution1470 s;
    vector <int> n = {2,5,1,3,4,7};
    vector <int> k = s.shuffle(n,n.size() / 2);
    for(int i = 0 ; i < k.size() ; i++)
    cout << k[i] << " ";

}

