#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
vector<int> v = {2};
    int countPrimes(int n) {
        if(n <= 2) return 0;

        for(int i = 3 ; i < n ;  i += 2 ){
    bool isPrime = true;
    for (int p : v) {
        if (p * p > i) break;
        if (i % p == 0) {
            isPrime = false;
            break;
        }
    }
 if(isPrime) v.push_back(i);
}
return v.size();
    }
};
int main(){
Solution s;
cout << s.countPrimes( 6);
}