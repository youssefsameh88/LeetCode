class Solution(object):
    def reverse(self, x):
     y = 0
     n = abs(x)
     mult = 10**(len(str(abs(x)))-1)
     while n != 0:
         y += (n % 10) *mult
         n = int(n / 10)
         mult = int(mult / 10)
     if not (-2**31 <= y < 2**31):
         return 0
     return y if x > 0 else -y   
print(Solution().reverse(-19))