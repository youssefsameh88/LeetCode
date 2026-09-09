#include <iostream>
using namespace std;

class Solution {
public:
    int gcdOfOddEvenSums(int n) {
       int sumEven = n * (n+1);
       int sumOdd = n*n;

    while (sumOdd != 0) {
        int r = sumEven % sumOdd;
        sumEven = sumOdd;
        sumOdd = r;
    }
    return sumEven;

    }
};

int main(){
    Solution s;
    cout << s.gcdOfOddEvenSums(5);
}