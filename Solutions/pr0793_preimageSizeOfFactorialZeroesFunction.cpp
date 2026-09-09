class Solution {
public:
    int preimageSizeFZF(int k) {
        long  l = findBoundary(k, true);
        if(l == -1) return 0;
        long  r = findBoundary(k, false);
        return r - l + 1;
    }
    long trailingZeroes(long n) {
        if(n < 5) return 0;
        long f = 5 ;
        long  sum = 0;
        
        while(n/f > 0){
            sum += n/f;
            f *= 5;
        }
        return sum;
    }
    int findBoundary(int target, bool findFirst) {
    long  left = 0;
    long  right = 5 * 1e9;
    long  result = -1;

    while (left <= right) {
        long  mid = left + (right - left) / 2;
        long  x =  trailingZeroes(mid);
        if (x == target) {
            result = mid; 
            if (findFirst) right = mid - 1; 
            else left = mid + 1;
        } 
        else if (x < target) left = mid + 1; 
        else right = mid - 1;
    }
    return result;
}
};