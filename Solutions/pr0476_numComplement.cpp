class Solution {
public:
    int findComplement(int num) {
        int x = __builtin_clz(num);
        return (~(num << x) >> x);
    }
};
