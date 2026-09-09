#include <vector>
using namespace std;
class Solution {
public:
    int sumOfPrimesInRange(int n) {
        int sum = 0, m = reverse(n);
        int Min = min(m,n), Max = max(m, n);
         
    vector<bool> primes(Max + 1, true);
    primes[0] = primes[1] = false;

    for (int p = 2; p * p <= Max; p++) {
        if (primes[p])
            for (int i = p * p; i <= Max; i += p) 
                primes[i] = false;
    }
        for(int i = Min ; i <= Max ; i++)
            if(primes[i]) sum += i;
        
        return sum;
    }
    int reverse(int n){
        int ans = 0;
        while(n > 0){
            ans = ans * 10 + n % 10;
            n /= 10;
        }
        return ans;
    }
};