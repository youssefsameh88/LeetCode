class Solution(object):
    def divide(self, dividend, divisor):
     max_Int = 2**31 -1
     min_Int = - 2**31
     if abs(dividend) < abs(divisor):
        return 0
     positive = not ( (dividend < 0) ^ (divisor < 0))
     st1 = [divisor] 
     fits = divisor
     st2 = [1]
     ans = 1
     while True:
        if abs(fits) <= abs(dividend):
           st1.append(st1[-1] + st1[-1])
           st2.append(st2[-1] + st2[-1])
           fits += st1[-1]
           ans += st2[-1]
        else:
           fits -= st1.pop()
           ans -= st2.pop()
           if len(st1):
            fits+=st1[-1]
            ans +=st2[-1]
           else:
              break
     ans = ans if positive else -ans 
     if ans > max_Int:
        return max_Int
     elif ans < min_Int:
        return min_Int
     else:
        return ans  
           
           
print(Solution().divide(-2147483648,1))