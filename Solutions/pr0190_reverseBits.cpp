class Solution {
public:
    int reverseBits(int n) {
      unsigned int m = 0;
    int i = 0;
        while (i < 31){
        m += n&1;
        m <<= 1;
        n >>= 1;
        i++;
        }
        return m;
    }
};