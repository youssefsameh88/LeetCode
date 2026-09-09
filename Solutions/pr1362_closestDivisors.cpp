#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> closestDivisors(int num) {
        vector<int> nump1 = getDivs(num+1);
        vector<int> nump2 = getDivs(num+2);
        int n1 = 0, n2 = 0, mn = INT_MAX;
        num++;
        for(int i = 0; i < nump1.size(); i++){
            int x = nump1[i] - num/nump1[i]; 
            if(abs(x) < mn){
                mn = abs(x);
                n1 = nump1[i], n2 = nump1[i] - x;
            }
        }
        num++;
        for(int i = 0; i < nump2.size(); i++){
            int x = nump2[i] - num/nump2[i];
            if(abs(x) < mn){
                mn = abs(x);
                n1 = nump2[i], n2 = nump2[i]-x;
            }
        }
        return {n1,n2};
    }

    vector<int> getDivs(int n) {
        vector<int> divisors;

        for (int i = 1; i * i <= n; i++) {
            if (n % i == 0) {
                divisors.push_back(i);

                if (i != n / i)
                    divisors.push_back(n / i);
            }
        }
        sort(divisors.begin(),divisors.end());
        return divisors;
    }
};