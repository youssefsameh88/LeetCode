#include <iostream>
#include <cmath>
using namespace std;

class Solution {
public:
    long long countCommas(long long n) {
      
       long long k = n;
       int count = 0;
       while(k){
        count++;
        k/=10;
       }
       
       int commas = count/3 - (count%3 == 0);
       long long sub = pow(10,3*commas) - 1;

       long long m = (n - sub)*commas;
       while(commas){
           commas--;
        m += (sub - sub/1000)*commas;
        sub /= 1000;
       }
       return m;
    }
};


int main(){
    Solution s;
    cout << s.countCommas(1234567891011);
}