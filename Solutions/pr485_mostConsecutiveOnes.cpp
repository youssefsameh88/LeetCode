#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
    int findMaxConsecutiveOnes(vector<int> &nums)
    {
        int c = 0;
        int max = 0;
        for (int i = 0; i < nums.size(); i++){
            if (nums[i]){
                c++;
                if(c > max) max = c;
            }
            else if( !nums[i]){
                c = 0;
            }
        }
        return max;
    }
};
int main(){
Solution s;
vector v = {1,1,0,1,1,1};
cout << s.findMaxConsecutiveOnes(v);

}