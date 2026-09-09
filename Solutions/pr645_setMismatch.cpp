#include <iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        unordered_map <int , int > map ;

        int dup = 0, miss = 0;
        for(int x : nums){
            if(map.find(x) != map.end()) 
                dup = x;

            map[x]++;

            if (map[x] == 2)
                dup = x;
        }

        for(int i = 1 ; i <= nums.size()  ; i++){
            if(map.find(i) == map.end()){
                miss = i;
                break;
            }
        }
        return {dup , miss};
        
        
    }
};

int main(){
    Solution s;
    vector v = {1,1};
    vector ans = s.findErrorNums(v);

    for (size_t i = 0; i < ans.size() ; i++)
    {
        cout << ans[i] << " ";
    }
    
}


