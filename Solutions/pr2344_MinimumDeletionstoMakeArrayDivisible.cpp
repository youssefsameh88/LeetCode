#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& numsDivide) {
        int GCD = gcdArray(numsDivide);
        sort(nums.begin() , nums.end());
        int count = 0 , i = 0;
        for( i = 0; i < nums.size() ; i ++){
            if(GCD % nums[i] == 0) break;

                count++;
        }
        if( nums.size() == count) return -1;
        return count;
    }
    int gcd(int a, int b) {
    while (b != 0) {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int gcdArray(vector<int>& numbers) {
    int g = numbers[0];
    for (int i = 1; i < numbers.size(); i++) {
        g = gcd(g, numbers[i]);
    }
    return g;
}
};

int main(){
    Solution s;
    vector arr1 = {4,3,6};
    vector arr2 = {8,2,6,10};
    cout << s.minOperations(arr1,arr2);
}