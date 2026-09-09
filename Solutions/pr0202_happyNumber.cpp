class Solution {
public:
    bool isHappy(int n) {
        while(true){
          int sum = 0;
            if(n == 1) return true;
            else if(n == 4 || n == 9 ) return false;
          while(n){
            sum += (n%10)*(n%10);
            n /= 10;
          }
            n = sum;
        }
            return false;
    }
};