#include <iostream>
#include<cmath>
using namespace std;

class Solution633 {
public:
    bool judgeSquareSum(int c) {;
        int low = 0;
        int high = sqrt(c);

        while (low <= high){
            long long ans = (long long)low * low + (long long)high * high;
            if(ans > c) high--;
            else if (ans < c) low++;
            else return true;
        }
        return false;
        
    }
};
int main(){
    Solution633 s;
    cout << s.judgeSquareSum(2147482647);

}