#include <iostream>
using namespace std;
class Solution {
public:
    int findNthDigit(int n) {
        if(n < 10) return n;
        n -=9;
        long long m = 90;
        int mult = 2;
        while(n > m*mult){
            n-= m*mult;
            m*=10;
            mult++;
       }     
        int start = 1;
        for(int i = 1; i < mult; i++){
            start *= 10;
        }
        start += (n-1)/mult;
        int mod = (n-1)%(mult);
        mod = (mult - mod-1)%mult;
        cout << mod <<" " << start<<  endl;
        for(int i = 0 ; i < mod; i++){
            start /= 10;
        }
        return start%10;   
    }
}; 

int main(){
    Solution s;
   cout << s.findNthDigit(3008);
}