import math
class Solution:
    def smallestGoodBase(self, n: str) -> str:
        num = int(n)
        minBase = float(num - 1)
        maxM = math.floor(math.log2(num))
        for m in range(2,maxM+1):
            l = 2
            r = num - 1
            while l <= r:
                mid = (l + r)//2
                x = self.calc(num,mid,m)
                if x < 0: l = mid + 1
                elif x > 0: r = mid - 1
                else :
                    if mid < minBase: minBase = mid
                    break
        if minBase > num**(1/2): return str(num-1)
        return str(int(minBase))
    def calc(self,n: int, b: int, m: float) -> float:
         val = 0
         for i in range(m+1):
             val += b**i
             if(val > n): return 1
         if(val < n): return -1
         else: return 0

                

sol = Solution()
x = 15
print(sol.smallestGoodBase(str(x)))
print(len(str(x)))