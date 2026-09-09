#include <iostream>
#include <vector>
using namespace std;

class Solution167 {
public:
vector<int> twoSum(vector<int>& numbers, int target) {
    int l = 0;
    int h = numbers.size()-1;
        
            while(l <= h){
                int ans = numbers[l] + numbers[h];

                if(ans > target) h--;
                else if(ans < target) l++;
                else
                    return {l+1 , h+1};
            }
        return {0,0};
    }
};
int main(){
    Solution167 s;
    vector<int> v = {-1,0};
    int t = -1;
    vector<int> a = s.twoSum(v,t);
    cout << a[0] << " "<< a[1];
}