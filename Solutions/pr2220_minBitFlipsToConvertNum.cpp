class Solution {
public:
    int minBitFlips(int start, int goal) {
        int sum = 0;
        int XOR = start ^ goal;
        while(XOR){
            sum += XOR & 1;
            XOR >>= 1;
        }
        return sum;
    }
};