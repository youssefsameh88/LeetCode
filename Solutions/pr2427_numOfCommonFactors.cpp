#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int commonFactors(int a, int b) {
        int count = 0;
        set<int> aDiv = divisors(a);
        set<int> bDiv = divisors(b);
        for(auto n : aDiv){
            if(bDiv.count(n)) count++;
        }
        return count;
    }
    set<int> divisors(int num){
        set<int> s;
        s.insert(1);
        for(int i = 2; i*i <= num; i++){
            if(num%i == 0){
                s.insert(i);
                s.insert(num/i);
            }
        }
        s.insert(num);
        return s;
    }
};