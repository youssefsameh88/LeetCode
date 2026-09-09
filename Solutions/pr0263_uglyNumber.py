class Solution(object):
    def isUgly(self, n):
      if not n:
         return False
      for i in [2,3,5]:
         while  not (n % i) or n == 1:
            if n == 1:
               return True
            n /= i
      return False

         
        
print(Solution().isUgly(14))