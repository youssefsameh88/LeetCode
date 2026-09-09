#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
    int minSteps(int n) {
        if(n == 1) return 0;
         vector<bool> isPrime(n + 1, true);
    vector<int> primes;

    isPrime[0] = isPrime[1] = false;

    for (int p = 2; p * p <= n; p++) 
        if (isPrime[p]) 
            for (int i = p * p; i <= n; i += p) isPrime[i] = false;
    
    for (int i = 2; i <= n; i++)
        if (isPrime[i]) primes.push_back(i);
    

        vector<int> primeFactors;        
        
        for(int i = 0 ; i < primes.size() ; i++){
            if(n%(primes[i]) == 0){
                primeFactors.push_back(primes[i]);
                n /= primes[i];
                i = -1;
            }
        }

        int sum = 0;
        for(int k : primeFactors) sum += k;

        return sum;
    }
 };

