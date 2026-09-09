#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    char kthCharacter(long long k, vector<int>& operations) {
        if(k == 1) return 'a';
        return helper(k, operations.size() +1, operations);
    }
    char helper(long long k, int n, vector<int>& op){
        if(n == 2) {
            return k == 2 && op[0] ? 'b' : 'a';  
        }
        if(n <= 48){
            long long x = 1LL << (n-2);
            if(k > x){
            if(op[n-2]) return next(helper(k - x ,n-1,op));
            else return helper(k - x ,n-1,op);
            }
        }
        
        return helper(k, n-1, op);
    }
    char next(char c){
        return (char)((c -'a' + 1)%26 + 'a') ;
    }
};