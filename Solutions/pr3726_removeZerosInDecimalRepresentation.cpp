class Solution {
public:
    long long removeZeros(long long n) {
        long long mult = 1, ans = 0;
        while(n > 0){
            int x = n % 10;
            if(x){
                ans += mult*x;
                mult *= 10;
            }
            n /= 10;
        }
        return ans;
    }
};