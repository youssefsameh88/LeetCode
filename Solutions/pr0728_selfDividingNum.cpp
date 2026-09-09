#include <vector>
using namespace std;

class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> v;
        for(int i = left ; i <= right; i++){
            if(helper(i)) v.push_back(i); 
        }
        return v;
    }
    bool helper(int n){
        int m = n;
        while(m > 0){
            int mod = m%10;
            if(!mod || n % mod != 0) return false;
            m /= 10;
        }
        return true;
    }
};
