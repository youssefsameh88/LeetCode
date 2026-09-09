#include <cmath>
#include <iostream>
class Solution {
public:
    int climbStairs(int n) {
       double n1 = (1+sqrt(5))/2; 
       double n2 = (1-sqrt(5))/2;
       return (pow(n1,n+1) - pow(n2,n+1))/sqrt(5); 
    }
};
int main(){
    Solution s;
    for(int i = 1; i < 45; i++)
    std::cout << s.climbStairs(i) << std::endl;
}