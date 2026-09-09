class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
    long long mult = 1;
    unsigned int n = 0;
    int sub = right ^ left;
     while(sub  >= mult){
        mult *= 2;
        n = n*2 + 1;
     }
     return right & ~n;
    }
};