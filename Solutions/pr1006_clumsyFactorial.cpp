class Solution {
public:
    int clumsy(int n) {
        if(n < 3) return n;
        if(n < 5) return n + 3;
       if(n%4 == 0) return n + 1;
       if(n%4 < 3) return n + 2;
       return n - 1;
    }
};
