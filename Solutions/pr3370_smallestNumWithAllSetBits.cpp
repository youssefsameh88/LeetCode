class Solution {
public:
    int smallestNumber(int n) {
        int i = 0, num = 0;
        while(num < n){
            num += 1<<i;
            i++;
        }
        return num;
    }
};