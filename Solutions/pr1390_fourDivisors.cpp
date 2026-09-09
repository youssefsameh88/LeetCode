#include <vector>
using namespace std;

class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int sum = 0;
        for(int num : nums){
                vector <int> v = calc4Divisors(num);
                for(int i : v) sum += i;
        }
        return sum;
    }

    vector <int> calc4Divisors(int num){
        vector <int> divisors;

        for(int i = 1; i < num ; i++){
            if(i > num/2) i = num;
            if(num%i == 0) divisors.push_back(i);
            if(divisors.size() > 4) break;
        }
        if(divisors.size() == 4)
            return divisors;
        return {0};
    }
};