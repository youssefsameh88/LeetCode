#include <iostream>
class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n == 1) return true;
        if(n%2 || n <= 0) return false;
        int m = 1, limit = 1 << 30;
        while(m < n && m < limit){
            m <<= 2;
            if(m == n) return true;
        }
        return false;
    }
};

int main(){
    Solution s;
    std::cout << s.isPowerOfFour(5);
}