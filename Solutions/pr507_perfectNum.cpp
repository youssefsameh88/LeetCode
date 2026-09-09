class Solution {
public:
    bool checkPerfectNumber(int num) {
        int sum = 0, n = num/2;
        for(int i = 1; i <= n ; i++ ){
            if(num % i == 0) sum += i;
        }
        return num == sum;
    }
};