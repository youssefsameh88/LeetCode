class Solution {
public:
    int concatenatedBinary(int n) {
        long long ans = 1;
        int mod = 1e9 + 7;
        for(int i = 2; i <= n; i++) ans = ((ans << (32-__builtin_clz(i))) + i)% mod;
        return ans;
    }
};
