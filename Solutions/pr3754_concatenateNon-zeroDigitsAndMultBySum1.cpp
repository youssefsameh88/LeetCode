class Solution {
public:
    long long sumAndMultiply(int n) {
        long long N = 0;
        int sum = 0;
        int num = 1;
        while(n){
            int mod = n%10;
            if(mod != 0){
                N += mod * num ;
                num *= 10;
            } 
            sum += mod;
            n /= 10;
        }
        return sum * N;
    }
};